import type { UnistylesRuntime } from './runtime'
import type { UnistylesState } from './state'
import type { UnistylesShadowRegistry } from './shadowRegistry'
import type { UnistylesListener } from './listener'
import type { UnistylesRegistry } from './registry'

export type UnistylesWebServices = {
    UnistylesRuntime: UnistylesRuntime
    UnistylesState: UnistylesState,
    UnistylesShadowRegistry: UnistylesShadowRegistry,
    UnistylesListener: UnistylesListener,
    UnistylesRegistry: UnistylesRegistry
}
