import { type UnistylesRuntime as UnistylesRuntimeSpec } from './UnistylesRuntime.nitro'
import {
    type AppBreakpoint,
    type AppTheme,
    type AppThemeName,
    type ColorScheme,
    type Dimensions, type Insets,
    Orientation
} from '../types'
import { AndroidContentSizeCategory, type IOSContentSizeCategory } from '../../common'
import type { StatusBar } from '../StatusBar'
import type { NavigationBar } from '../NavigtionBar'

export interface UnistylesRuntime extends UnistylesRuntimeSpec {
    readonly colorScheme: ColorScheme,
    readonly themeName: AppThemeName,
    readonly contentSizeCategory: IOSContentSizeCategory | AndroidContentSizeCategory,
    readonly breakpoint: AppBreakpoint,
    readonly orientation: Orientation,

    // other HybridObjects
    statusBar: StatusBar,
    navigationBar: NavigationBar,

    setTheme(themeName: AppThemeName): void
    updateTheme(themeName: AppThemeName, updater: (currentTheme: AppTheme) => AppTheme): void,
    setRootViewBackgroundColor(hex?: `#${string}`, alpha?: number): void
}

export interface MiniRuntime {
    readonly contentSizeCategory: IOSContentSizeCategory | AndroidContentSizeCategory,
    readonly breakpoint: AppBreakpoint
    readonly screen: Dimensions
    readonly insets: Insets
    readonly statusBar: Dimensions
    readonly navigationBar: Dimensions
    readonly orientation: Orientation
    readonly pixelRatio: number
    readonly fontScale: number
}