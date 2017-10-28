#pragma once

#include <Wire.h>
#include "SparkFun_APDS9960.h"
#include "consts.h"

SparkFun_APDS9960 apds = SparkFun_APDS9960();

inline int colorTree(int ambient, int red, int green, int blue) {
  if (ambient <= 1664.5) {
    if (red <= 344.5) {
      if (green <= 305.0) {
        if (red <= 166.0) {
          if (ambient <= 363.0) {
              return 0;
            } else {
              return 4;
            } // end else
          } else {
            return 5;
          } // end else
        } else {
          return 2;
        } // end else
      } else {
        return 3;
      } // end else
    } else {
      return 1;
    }// end else
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

    return Color(colorTree(ambient_light, red_light, green_light, blue_light));
}