import React, { type ComponentType, forwardRef, type ComponentProps, type ComponentRef } from 'react'
import type { PartialBy } from '../../types/common'
import { UnistylesListener } from '../../web/listener'
import { deepMergeObjects } from '../../utils'
import type { Mappings, SupportedStyleProps } from './types'
import { useDependencies } from './useDependencies'
import { UnistyleDependency } from '../../specs/NativePlatform'
import type { UnistylesValues } from '../../types'
import { useClassname } from '../../hooks'

// @ts-expect-error
type GenericComponentProps<T> = ComponentProps<T>
// @ts-expect-error
type GenericComponentRef<T> = ComponentRef<T>

export const withUnistyles = <TComponent, TMappings extends GenericComponentProps<TComponent>>(Component: TComponent, mappings?: Mappings<TMappings>) => {
    type TProps = GenericComponentProps<TComponent>
    type PropsWithUnistyles = PartialBy<TProps, keyof TMappings | SupportedStyleProps> & {
        uniProps?: Mappings<TProps>
        style?: UnistylesValues,
        contentContainerStyle?: UnistylesValues
    }

    return forwardRef<GenericComponentRef<TComponent>, PropsWithUnistyles>((props, ref) => {
        const narrowedProps = props as PropsWithUnistyles
        const styleClassNames = useClassname(narrowedProps.style)
        const contentContainerStyleClassNames = useClassname(narrowedProps.contentContainerStyle)
        const { mappingsCallback } = useDependencies(({ dependencies, updateTheme, updateRuntime }) => {
            const disposeTheme = UnistylesListener.addListeners(dependencies.filter(dependency => dependency === UnistyleDependency.Theme), updateTheme)
            const disposeRuntime = UnistylesListener.addListeners(dependencies.filter(dependency => dependency !== UnistyleDependency.Theme), updateRuntime)

            return () => {
                disposeTheme()
                disposeRuntime()
            }
        })
        const mappingsProps = mappings ? mappingsCallback(mappings) : {}
        const unistyleProps = narrowedProps.uniProps ? mappingsCallback(narrowedProps.uniProps) : {}

        const combinedProps = {
            ...deepMergeObjects(mappingsProps, unistyleProps, props),
            ...narrowedProps.style ? {
                style: styleClassNames,
            } : {},
            ...narrowedProps.contentContainerStyle ? {
                style: contentContainerStyleClassNames,
            } : {},
        } as any

        const NativeComponent = Component as ComponentType

        return <NativeComponent {...combinedProps} ref={ref} />
    })
}
