// VolumeChange.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <objbase.h>

int main()
{
	HRESULT hr = NULL;
	double mainVolume = 1.0;
	double leftVolume = 0.25;
	double rightVolume = 1.0;

	CoInitialize(NULL);
	IMMDeviceEnumerator *deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
	IMMDevice *defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume *endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	// -------------------------
	float currentVolume = 0;
	UINT channelCount;

	hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
	// printf("Current volume as a scalar is: %f\n", currentVolume);

	hr = endpointVolume->SetMasterVolumeLevelScalar((float)mainVolume, NULL);
	// printf("Current volume as a scalar is now: %f\n", mainVolume);

	hr = endpointVolume->GetChannelCount(&channelCount);
	// printf("Channel count is: %d\n", channelCount);

	hr = endpointVolume->SetChannelVolumeLevelScalar((UINT)0, (float)leftVolume, NULL);
	hr = endpointVolume->SetChannelVolumeLevelScalar((UINT)1, (float)rightVolume, NULL);

	endpointVolume->Release();
	CoUninitialize();

    return 0;
}