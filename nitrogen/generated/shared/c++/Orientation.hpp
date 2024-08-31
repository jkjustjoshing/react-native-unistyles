///
/// Orientation.hpp
/// Sat Aug 31 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/NitroHash.hpp>)
#include <NitroModules/NitroHash.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/JSIConverter.hpp>)
#include <NitroModules/JSIConverter.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/NitroDefines.hpp>)
#include <NitroModules/NitroDefines.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

namespace margelo::nitro::unistyles {

  /**
   * An enum which can be represented as a JavaScript union (Orientation).
   */
  enum class Orientation {
    PORTRAIT      SWIFT_NAME(portrait) = 0,
    LANDSCAPE      SWIFT_NAME(landscape) = 1,
  } CLOSED_ENUM;

} // namespace margelo::nitro::unistyles

namespace margelo::nitro {

  using namespace margelo::nitro::unistyles;

  // C++ Orientation <> JS Orientation (union)
  template <>
  struct JSIConverter<Orientation> {
    static inline Orientation fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      std::string unionValue = JSIConverter<std::string>::fromJSI(runtime, arg);
      switch (hashString(unionValue.c_str(), unionValue.size())) {
        case hashString("portrait"): return Orientation::PORTRAIT;
        case hashString("landscape"): return Orientation::LANDSCAPE;
        default: [[unlikely]]
          throw std::runtime_error("Cannot convert \"" + unionValue + "\" to enum Orientation - invalid value!");
      }
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, Orientation arg) {
      switch (arg) {
        case Orientation::PORTRAIT: return JSIConverter<std::string>::toJSI(runtime, "portrait");
        case Orientation::LANDSCAPE: return JSIConverter<std::string>::toJSI(runtime, "landscape");
        default: [[unlikely]]
          throw std::runtime_error("Cannot convert Orientation to JS - invalid value: "
                                    + std::to_string(static_cast<int>(arg)) + "!");
      }
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isString()) {
        return false;
      }
      std::string unionValue = JSIConverter<std::string>::fromJSI(runtime, value);
      switch (hashString(unionValue.c_str(), unionValue.size())) {
        case hashString("portrait"):
        case hashString("landscape"):
          return true;
        default:
          return false;
      }
    }
  };

} // namespace margelo::nitro
