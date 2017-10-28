#pragma once

#include <Wire.h>
#include "SparkFun_APDS9960.h"
#include "consts.h"

SparkFun_APDS9960 apds = SparkFun_APDS9960();

inline int colorTree(float ambient, float green, float blue) {
  if (ambient <= 4.074999809265137) {
    if (blue <= 0.36413997411727905) {
      if (ambient <= 2.0850000381469727) {
        if (green <= 0.0031049998942762613) {
          return 5;
        } else { // if green > 0.0031049998942762613
          if (green <= 113.96139526367188) {
            if (green <= 57.47780990600586) {
              if (blue <= 0.004664999898523092) {
                if (green <= 1.993575096130371) {
                  return 1;
                } else { // if green > 1.993575096130371
                  if (green <= 8.675785064697266) {
                    return 4;
                  } else { // if green > 8.675785064697266
                    return 3;
                  }
                }
              } else { // if blue > 0.004664999898523092
                return 0;
              }
            } else { // if green > 57.47780990600586
              return 2;
            }
          } else { // if green > 113.96139526367188
            if (green <= 140.12652587890625) {
              return 0;
            } else { // if green > 140.12652587890625
              return 4;
            }
          }
        }
      } else { // if ambient > 2.0850000381469727
        if (blue <= 0.0034650000743567944) {
          return 0;
        } else { // if blue > 0.0034650000743567944
          return 3;
        }
      }
    } else { // if blue > 0.36413997411727905
      if (green <= 0.4777649939060211) {
        if (blue <= 0.5720199942588806) {
          if (ambient <= 2.9049999713897705) {
            if (ambient <= 1.2899999618530273) {
              if (green <= 0.25987499952316284) {
                return 4;
              } else { // if green > 0.25987499952316284
                if (blue <= 0.4436299800872803) {
                  return 0;
                } else { // if blue > 0.4436299800872803
                  return 3;
                }
              }
            } else { // if ambient > 1.2899999618530273
              return 5;
            }
          } else { // if ambient > 2.9049999713897705
            return 0;
          }
        } else { // if blue > 0.5720199942588806
          return 4;
        }
      } else { // if green > 0.4777649939060211
        if (green <= 0.7441450357437134) {
          if (green <= 0.516539990901947) {
            return 2;
          } else { // if green > 0.516539990901947
            if (green <= 0.5243300199508667) {
              return 4;
            } else { // if green > 0.5243300199508667
              if (blue <= 0.4432550072669983) {
                return 3;
              } else { // if blue > 0.4432550072669983
                return 2;
              }
            }
          }
        } else { // if green > 0.7441450357437134
          if (ambient <= 0.75) {
            return 4;
          } else { // if ambient > 0.75
            if (ambient <= 2.129999876022339) {
              return 0;
            } else { // if ambient > 2.129999876022339
              return 3;
            }
          }
        }
      }
    }
  } else { // if ambient > 4.074999809265137
    if (ambient <= 24.10999870300293) {
      return 1;
    } else { // if ambient > 24.10999870300293
      if (blue <= 0.013659999705851078) {
        return 4;
      } else { // if blue > 0.013659999705851078
        return 3;
      }
    }
  }
}

inline Color getColor() {
    uint16_t ambient_light = 0;
    uint16_t red_light = 0;
    uint16_t green_light = 0;
    uint16_t blue_light = 0;

    apds.readAmbientLight(ambient_light);
    apds.readRedLight(red_light);
    apds.readGreenLight(green_light);
    apds.readBlueLight(blue_light);

    float red = red_light;
    return Color(colorTree(
        ambient_light / red,
        green_light / red,
        blue_light / red
    ));
}