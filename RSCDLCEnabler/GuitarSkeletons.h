#pragma once
#include "windows.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Structs.h"

class cGuitarSkeletons {
public:
	xyzPosition StringAttachPosition(bool leftHanded, bool bass, int stringNumber, bool setToDefaults, double inputZ);
	xyzPosition FretBarPosition(bool leftHanded, bool topOfFretBar, bool setToDefaults, int fretNumber, double inputZ);
	xyzPosition CameraMarkerPosition(bool leftHanded, bool tipOfCameraMarker, bool topOfCameraMarker, bool setToDefaults, double inputZ);

private:
	xyzPosition GetSkeletonPosition();
	double X, Y, Z;
};

extern cGuitarSkeletons GuitarSkeletons;