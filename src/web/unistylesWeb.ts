import { UnistylesListener } from './listener'
import { UnistylesRegistry } from './registry'
import { UnistylesRuntime } from './runtime'
import { UnistylesShadowRegistry } from './shadowRegistry'
import { UnistylesState } from './state'
import type { UnistylesWebServices } from './types'

class UnistylesWebBuilder {
    UnistylesRuntime: UnistylesRuntime
    UnistylesState: UnistylesState
    UnistylesShadowRegistry: UnistylesShadowRegistry
    UnistylesListener: UnistylesListener
    UnistylesRegistry: UnistylesRegistry

    services = {} as UnistylesWebServices

    constructor() {
        this.UnistylesRuntime = new UnistylesRuntime(this.services)
        this.UnistylesState = new UnistylesState(this.services)
        this.UnistylesShadowRegistry = new UnistylesShadowRegistry(this.services)
        this.UnistylesListener = new UnistylesListener(this.services)
        this.UnistylesRegistry = new UnistylesRegistry(this.services)
    }
}

export const UnistylesWeb = new UnistylesWebBuilder()
