import { UnistyleDependency } from '../specs/NativePlatform'
import type { UnistylesWebServices } from './types'

export class UnistylesListener {
    private isInitialized = false
    private listeners = Array.from({ length: Object.keys(UnistyleDependency).length / 2 }, () => new Set<VoidFunction>())
    private stylesheetListeners = Array.from({ length: Object.keys(UnistyleDependency).length / 2 }, () => new Set<VoidFunction>())

    constructor(private services: UnistylesWebServices) {}

    emitChange = (dependency: UnistyleDependency) => {
        this.stylesheetListeners[dependency]?.forEach(listener => listener())
        this.listeners[dependency]?.forEach(listener => listener())
    }

    initListeners = () => {
        if (this.isInitialized) {
            return
        }

        this.isInitialized = true

        this.services.UnistylesRuntime.darkMedia?.addEventListener('change', event => {
            if (!event.matches) {
                return
            }

            this.emitChange(UnistyleDependency.ColorScheme)

            if (this.services.UnistylesRuntime.hasAdaptiveThemes) {
                this.emitChange(UnistyleDependency.Theme)
            }
        })
        this.services.UnistylesRuntime.lightMedia?.addEventListener('change', event => {
            if (!event.matches) {
                return
            }

            this.emitChange(UnistyleDependency.ColorScheme)

            if (this.services.UnistylesRuntime.hasAdaptiveThemes) {
                this.emitChange(UnistyleDependency.Theme)
            }
        })

        window.addEventListener('orientationchange', () => this.emitChange(UnistyleDependency.Orientation))
        window.addEventListener('resize', () => this.emitChange(UnistyleDependency.Dimensions))
    }

    addListeners = (dependencies: Array<UnistyleDependency>, listener: VoidFunction) => {
        dependencies.forEach(dependency => this.listeners[dependency]?.add(listener))

        return () => {
            dependencies.forEach(dependency => this.listeners[dependency]?.delete(listener))
        }
    }

    addStylesheetListeners = (dependencies: Array<UnistyleDependency>, listener: VoidFunction) => {
        dependencies.forEach(dependency => this.stylesheetListeners[dependency]?.add(listener))

        return () => {
            dependencies.forEach(dependency => this.stylesheetListeners[dependency]?.delete(listener))
        }
    }
}
