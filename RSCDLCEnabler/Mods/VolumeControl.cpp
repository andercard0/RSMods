#include "VolumeControl.hpp"

void VolumeControl::IncreaseVolume(int amountToIncrease, std::string mixerToIncrease) {
	float volume = 0;
	RTPCValue_type type = RTPCValue_GameObject;

	if (!MemHelpers::IsInStringArray(mixerToIncrease, NULL, mixerNames)) {
		std::cout << "That mixer doesn't exist" << std::endl;
		return;
	}

	WwiseVariables::Wwise_Sound_Query_GetRTPCValue_Char(mixerToIncrease.c_str(), 0xffffffff, &volume, &type); // Fill Volume Variable With Current Volume

	if (volume <= (100.0f - amountToIncrease))
		volume += amountToIncrease;
	else
		volume = 100.0f; // Incase the volume is within the amountToIncrease we can't throw it over 100.
	
	// Set Volume
	WwiseVariables::Wwise_Sound_SetRTPCValue_Char(mixerToIncrease.c_str(), (float)volume, 0xffffffff, 0, AkCurveInterpolation_Linear);
	WwiseVariables::Wwise_Sound_SetRTPCValue_Char(mixerToIncrease.c_str(), (float)volume, 0x00001234, 0, AkCurveInterpolation_Linear);
}

void VolumeControl::DecreaseVolume(int amountToDecrease, std::string mixerToDecrease) {
	float volume = 0;
	RTPCValue_type type = RTPCValue_GameObject;

	if (!MemHelpers::IsInStringArray(mixerToDecrease, NULL, mixerNames)) {
		std::cout << "That mixer doesn't exist" << std::endl;
		return;
	}

	WwiseVariables::Wwise_Sound_Query_GetRTPCValue_Char(mixerToDecrease.c_str(), 0xffffffff, &volume, &type); // Fill Volume Variable With Current Volume

	if (volume >= (0.0f + amountToDecrease))
		volume -= amountToDecrease;
	else
		volume = 0.0f; // Incase the volume is within the amountToDecrease we can't throw it below 0.

	// Set Volume
	WwiseVariables::Wwise_Sound_SetRTPCValue_Char(mixerToDecrease.c_str(), (float)volume, 0xffffffff, 0, AkCurveInterpolation_Linear);
	WwiseVariables::Wwise_Sound_SetRTPCValue_Char(mixerToDecrease.c_str(), (float)volume, 0x00001234, 0, AkCurveInterpolation_Linear);
}