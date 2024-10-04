#include "UnistylesCommitHook.h"

using namespace margelo::nitro::unistyles;
using namespace facebook::react;

core::UnistylesCommitHook::UnistylesCommitHook(UIManager& uiManager, std::shared_ptr<HybridUnistylesRuntime> unistylesRuntime)
    : _unistylesRuntime{unistylesRuntime} {
        uiManager.registerCommitHook(*this);
    };

core::UnistylesCommitHook::~UnistylesCommitHook() noexcept {}

void core::UnistylesCommitHook::commitHookWasRegistered(const UIManager &uiManager) noexcept {}
void core::UnistylesCommitHook::commitHookWasUnregistered(const UIManager &uiManager) noexcept {}

RootShadowNode::Unshared core::UnistylesCommitHook::shadowTreeWillCommit(
    const ShadowTree &shadowTree,
    const RootShadowNode::Shared &oldRootShadowNode,
    const RootShadowNode::Unshared &newRootShadowNode
) noexcept {
    RootShadowNode::Unshared rootNode = newRootShadowNode;
    auto unistylesRootNode = std::reinterpret_pointer_cast<core::UnistylesCommitShadowNode>(newRootShadowNode);
    
    // skip only unistyles commits
    if (unistylesRootNode->hasUnistylesCommitTrait()) {
        unistylesRootNode->removeUnistylesCommitTrait();
        
        return newRootShadowNode;
    }

    auto shadowLeafUpdates = this->getUnistylesUpdates();
    
    if (shadowLeafUpdates.size() == 0) {
        return newRootShadowNode;
    }
    
    auto affectedNodes = shadow::ShadowTreeManager::findAffectedNodes(*rootNode, shadowLeafUpdates);

    return std::static_pointer_cast<RootShadowNode>(shadow::ShadowTreeManager::cloneShadowTree(
        this->_unistylesRuntime->getRuntime(),
        *rootNode,
        shadowLeafUpdates,
        affectedNodes
    ));
}

shadow::ShadowLeafUpdates core::UnistylesCommitHook::getUnistylesUpdates() {
    auto& registry = core::UnistylesRegistry::get();
    auto parser = parser::Parser(this->_unistylesRuntime);
    auto dependencyMap = registry.buildDependencyMap();
    
    return parser.dependencyMapToShadowLeafUpdates(dependencyMap);
}