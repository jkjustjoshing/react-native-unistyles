import { create } from './create'
import { deepMergeObjects } from '../utils'
import type { StyleSheet as NativeStyleSheet } from '../specs/StyleSheet'
import type { Runtime as NativeUnistylesRuntime } from '../specs/UnistylesRuntime'
import { UnistylesWeb } from './unistylesWeb'

export const StyleSheet = {
    configure: UnistylesWeb.UnistylesState.init,
    create: create,
    absoluteFill: {
        position: 'absolute',
        left: 0,
        top: 0,
        right: 0,
        bottom: 0,
    },
    absoluteFillObject: {
        position: 'absolute',
        left: 0,
        top: 0,
        right: 0,
        bottom: 0
    },
    compose: (a: object, b: object) => deepMergeObjects(a, b),
    flatten: (...styles: Array<object>) => deepMergeObjects(...styles),
    hairlineWidth: 1
} as unknown as typeof NativeStyleSheet

export const UnistylesRuntime = UnistylesWeb.UnistylesRuntime as unknown as typeof NativeUnistylesRuntime
export const UnistylesShadowRegistry = UnistylesWeb.UnistylesShadowRegistry

export * from './mock'
