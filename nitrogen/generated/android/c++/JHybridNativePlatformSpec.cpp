///
/// JHybridNativePlatformSpec.cpp
/// Wed Aug 21 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "JHybridNativePlatformSpec.hpp"



#include "JInsets.hpp"
#include "JColorScheme.hpp"
#include "JDimensions.hpp"

namespace margelo::nitro::unistyles {

  jni::local_ref<JHybridNativePlatformSpec::jhybriddata> JHybridNativePlatformSpec::initHybrid(jni::alias_ref<jhybridobject> jThis) {
    return makeCxxInstance(jThis);
  }

  void JHybridNativePlatformSpec::registerNatives() {
    registerHybrid({
      makeNativeMethod("initHybrid", JHybridNativePlatformSpec::initHybrid),
    });
  }

  size_t JHybridNativePlatformSpec::getExternalMemorySize() noexcept {
    static const auto method = _javaPart->getClass()->getMethod<jlong()>("getMemorySize");
    return method(_javaPart.get());
  }

  // Properties
  

  // Methods
  Insets JHybridNativePlatformSpec::getInsets() {
    static const auto method = _javaPart->getClass()->getMethod<JInsets()>("getInsets");
    throw std::runtime_error("getInsets(...) is not yet implemented!");
  }
  ColorScheme JHybridNativePlatformSpec::getColorScheme() {
    static const auto method = _javaPart->getClass()->getMethod<JColorScheme()>("getColorScheme");
    throw std::runtime_error("getColorScheme(...) is not yet implemented!");
  }
  double JHybridNativePlatformSpec::getFontScale() {
    static const auto method = _javaPart->getClass()->getMethod<double()>("getFontScale");
    throw std::runtime_error("getFontScale(...) is not yet implemented!");
  }
  double JHybridNativePlatformSpec::getPixelRatio() {
    static const auto method = _javaPart->getClass()->getMethod<double()>("getPixelRatio");
    throw std::runtime_error("getPixelRatio(...) is not yet implemented!");
  }
  std::string JHybridNativePlatformSpec::getContentSizeCategory() {
    static const auto method = _javaPart->getClass()->getMethod<std::string()>("getContentSizeCategory");
    throw std::runtime_error("getContentSizeCategory(...) is not yet implemented!");
  }
  Dimensions JHybridNativePlatformSpec::getScreenDimensions() {
    static const auto method = _javaPart->getClass()->getMethod<JDimensions()>("getScreenDimensions");
    throw std::runtime_error("getScreenDimensions(...) is not yet implemented!");
  }
  Dimensions JHybridNativePlatformSpec::getStatusBarDimensions() {
    static const auto method = _javaPart->getClass()->getMethod<JDimensions()>("getStatusBarDimensions");
    throw std::runtime_error("getStatusBarDimensions(...) is not yet implemented!");
  }
  Dimensions JHybridNativePlatformSpec::getNavigationBarDimensions() {
    static const auto method = _javaPart->getClass()->getMethod<JDimensions()>("getNavigationBarDimensions");
    throw std::runtime_error("getNavigationBarDimensions(...) is not yet implemented!");
  }
  bool JHybridNativePlatformSpec::getPrefersRtlDirection() {
    static const auto method = _javaPart->getClass()->getMethod<bool()>("getPrefersRtlDirection");
    throw std::runtime_error("getPrefersRtlDirection(...) is not yet implemented!");
  }
  void JHybridNativePlatformSpec::setRootViewBackgroundColor(const std::optional<std::string>& hex, std::optional<double> alpha) {
    static const auto method = _javaPart->getClass()->getMethod<void(std::optional<std::string>, std::optional<double>)>("setRootViewBackgroundColor");
    throw std::runtime_error("setRootViewBackgroundColor(...) is not yet implemented!");
  }
  void JHybridNativePlatformSpec::setNavigationBarBackgroundColor(const std::optional<std::string>& hex, std::optional<double> alpha) {
    static const auto method = _javaPart->getClass()->getMethod<void(std::optional<std::string>, std::optional<double>)>("setNavigationBarBackgroundColor");
    throw std::runtime_error("setNavigationBarBackgroundColor(...) is not yet implemented!");
  }
  void JHybridNativePlatformSpec::setNavigationBarHidden(bool isHidden) {
    static const auto method = _javaPart->getClass()->getMethod<void(bool)>("setNavigationBarHidden");
    throw std::runtime_error("setNavigationBarHidden(...) is not yet implemented!");
  }
  void JHybridNativePlatformSpec::setStatusBarBackgroundColor(const std::optional<std::string>& hex, std::optional<double> alpha) {
    static const auto method = _javaPart->getClass()->getMethod<void(std::optional<std::string>, std::optional<double>)>("setStatusBarBackgroundColor");
    throw std::runtime_error("setStatusBarBackgroundColor(...) is not yet implemented!");
  }
  void JHybridNativePlatformSpec::setImmersiveMode(bool isEnabled) {
    static const auto method = _javaPart->getClass()->getMethod<void(bool)>("setImmersiveMode");
    throw std::runtime_error("setImmersiveMode(...) is not yet implemented!");
  }

} // namespace margelo::nitro::unistyles