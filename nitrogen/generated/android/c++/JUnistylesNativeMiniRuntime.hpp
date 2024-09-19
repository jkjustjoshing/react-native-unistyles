///
/// JUnistylesNativeMiniRuntime.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include <fbjni/fbjni.h>
#include "UnistylesNativeMiniRuntime.hpp"

#include "ColorScheme.hpp"
#include "Dimensions.hpp"
#include "Insets.hpp"
#include "JColorScheme.hpp"
#include "JDimensions.hpp"
#include "JInsets.hpp"
#include "JOrientation.hpp"
#include "Orientation.hpp"
#include <string>

namespace margelo::nitro::unistyles {

  using namespace facebook;

  /**
   * The C++ JNI bridge between the C++ struct "UnistylesNativeMiniRuntime" and the the Kotlin data class "UnistylesNativeMiniRuntime".
   */
  struct JUnistylesNativeMiniRuntime final: public jni::JavaClass<JUnistylesNativeMiniRuntime> {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/unistyles/UnistylesNativeMiniRuntime;";

  public:
    /**
     * Convert this Java/Kotlin-based struct to the C++ struct UnistylesNativeMiniRuntime by copying all values to C++.
     */
    [[maybe_unused]]
    UnistylesNativeMiniRuntime toCpp() const {
      static const auto clazz = javaClassStatic();
      static const auto fieldColorScheme = clazz->getField<JColorScheme>("colorScheme");
      jni::local_ref<JColorScheme> colorScheme = this->getFieldValue(fieldColorScheme);
      static const auto fieldScreen = clazz->getField<JDimensions>("screen");
      jni::local_ref<JDimensions> screen = this->getFieldValue(fieldScreen);
      static const auto fieldContentSizeCategory = clazz->getField<jni::JString>("contentSizeCategory");
      jni::local_ref<jni::JString> contentSizeCategory = this->getFieldValue(fieldContentSizeCategory);
      static const auto fieldInsets = clazz->getField<JInsets>("insets");
      jni::local_ref<JInsets> insets = this->getFieldValue(fieldInsets);
      static const auto fieldPixelRatio = clazz->getField<double>("pixelRatio");
      double pixelRatio = this->getFieldValue(fieldPixelRatio);
      static const auto fieldFontScale = clazz->getField<double>("fontScale");
      double fontScale = this->getFieldValue(fieldFontScale);
      static const auto fieldRtl = clazz->getField<jboolean>("rtl");
      jboolean rtl = this->getFieldValue(fieldRtl);
      static const auto fieldStatusBar = clazz->getField<JDimensions>("statusBar");
      jni::local_ref<JDimensions> statusBar = this->getFieldValue(fieldStatusBar);
      static const auto fieldNavigationBar = clazz->getField<JDimensions>("navigationBar");
      jni::local_ref<JDimensions> navigationBar = this->getFieldValue(fieldNavigationBar);
      static const auto fieldOrientation = clazz->getField<JOrientation>("orientation");
      jni::local_ref<JOrientation> orientation = this->getFieldValue(fieldOrientation);
      return UnistylesNativeMiniRuntime(
        colorScheme->toCpp(),
        screen->toCpp(),
        contentSizeCategory->toStdString(),
        insets->toCpp(),
        pixelRatio,
        fontScale,
        rtl,
        statusBar->toCpp(),
        navigationBar->toCpp(),
        orientation->toCpp()
      );
    }

  public:
    /**
     * Create a Java/Kotlin-based struct by copying all values from the given C++ struct to Java.
     */
    [[maybe_unused]]
    static jni::local_ref<JUnistylesNativeMiniRuntime::javaobject> fromCpp(const UnistylesNativeMiniRuntime& value) {
      return newInstance(
        JColorScheme::fromCpp(value.colorScheme),
        JDimensions::fromCpp(value.screen),
        jni::make_jstring(value.contentSizeCategory),
        JInsets::fromCpp(value.insets),
        value.pixelRatio,
        value.fontScale,
        value.rtl,
        JDimensions::fromCpp(value.statusBar),
        JDimensions::fromCpp(value.navigationBar),
        JOrientation::fromCpp(value.orientation)
      );
    }
  };

} // namespace margelo::nitro::unistyles
