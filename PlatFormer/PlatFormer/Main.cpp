#include<Windows.h>
#include<mmsystem.h>
#include<Digitalv.h>
#include<iostream>
#include<Windows.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

MCI_OPEN_PARMS openBgm; //���� ���� ���� ����ü
MCI_OPEN_PARMS openSFX; //���� ���� ���� ����ü
MCI_PLAY_PARMS playBgm; //���� ��� ���� ����ü
MCI_PLAY_PARMS playSFX; //���� ��� ���� ����ü

UINT dwID;
void PlayingBgm()
{
	openBgm.lpstrElementName = TEXT("Sound/clearday.mp3");
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR) & openBgm);
	dwID = openBgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR) & openBgm);
}

UINT dwID2;
void PlayingSFX()
{
	openSFX.lpstrElementName = TEXT("Sound/Button.wav"); //���� ���
	openSFX.lpstrDeviceType = TEXT("waveaudio"); //mp3: mpegvideo, wav: waveaudio
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openSFX);
	dwID2 = openSFX.wDeviceID;

	mciSendCommand(dwID2, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&playSFX);
	Sleep(100);
	mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)&playSFX);
}

int main()
{
	PlayingBgm();
	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			PlayingSFX();
		}

	}

}