///
/// HybridNativePlatformSpec.kt
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

package com.margelo.nitro.unistyles

import android.util.Log
import androidx.annotation.Keep
import com.facebook.jni.HybridData
import com.facebook.proguard.annotations.DoNotStrip
import com.margelo.nitro.core.*

/**
 * A Kotlin class representing the NativePlatform HybridObject.
 * Implement this abstract class to create Kotlin-based instances of NativePlatform.
 */
@DoNotStrip
@Keep
@Suppress("RedundantSuppression", "KotlinJniMissingFunction", "PropertyName", "RedundantUnitReturnType", "unused")
abstract class HybridNativePlatformSpec: HybridObject() {
  protected val TAG = "HybridNativePlatformSpec"

  @DoNotStrip
  val mHybridData: HybridData = initHybrid()

  init {
    // Pass this `HybridData` through to it's base class,
    // to represent inheritance to JHybridObject on C++ side
    super.updateNative(mHybridData)
  }

  // Properties
  

  // Methods
  @DoNotStrip
  @Keep
  abstract fun getInsets(): Insets
  
  @DoNotStrip
  @Keep
  abstract fun getColorScheme(): ColorScheme
  
  @DoNotStrip
  @Keep
  abstract fun getFontScale(): Double
  
  @DoNotStrip
  @Keep
  abstract fun getPixelRatio(): Double
  
  @DoNotStrip
  @Keep
  abstract fun getOrientation(): Orientation
  
  @DoNotStrip
  @Keep
  abstract fun getContentSizeCategory(): String
  
  @DoNotStrip
  @Keep
  abstract fun getScreenDimensions(): Dimensions
  
  @DoNotStrip
  @Keep
  abstract fun getStatusBarDimensions(): Dimensions
  
  @DoNotStrip
  @Keep
  abstract fun getNavigationBarDimensions(): Dimensions
  
  @DoNotStrip
  @Keep
  abstract fun getPrefersRtlDirection(): Boolean
  
  @DoNotStrip
  @Keep
  abstract fun setRootViewBackgroundColor(color: Double): Unit
  
  @DoNotStrip
  @Keep
  abstract fun setNavigationBarBackgroundColor(color: Double): Unit
  
  @DoNotStrip
  @Keep
  abstract fun setNavigationBarHidden(isHidden: Boolean): Unit
  
  @DoNotStrip
  @Keep
  abstract fun setStatusBarHidden(isHidden: Boolean): Unit
  
  @DoNotStrip
  @Keep
  abstract fun setStatusBarBackgroundColor(color: Double): Unit
  
  @DoNotStrip
  @Keep
  abstract fun setImmersiveMode(isEnabled: Boolean): Unit
  
  @DoNotStrip
  @Keep
  abstract fun getMiniRuntime(): UnistylesNativeMiniRuntime
  
  @DoNotStrip
  @Keep
  abstract fun registerPlatformListener(callback: (dependencies: Array<UnistyleDependency>) -> Unit): Unit
  
  @DoNotStrip
  @Keep
  private fun registerPlatformListener(callback: Func_void_std__vector_UnistyleDependency_): Unit {
    val result = registerPlatformListener(callback.toLambda())
    return result
  }

  private external fun initHybrid(): HybridData

  companion object {
    private const val TAG = "HybridNativePlatformSpec"
    init {
      try {
        Log.i(TAG, "Loading unistyles C++ library...")
        System.loadLibrary("unistyles")
        Log.i(TAG, "Successfully loaded unistyles C++ library!")
      } catch (e: Error) {
        Log.e(TAG, "Failed to load unistyles C++ library! Is it properly installed and linked? " +
                    "Is the name correct? (see `CMakeLists.txt`, at `add_library(...)`)", e)
        throw e
      }
    }
  }
}
