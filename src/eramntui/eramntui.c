/*�@ERAMNTUI.C�@�@RAM�f�B�X�NERAM for WindowsNT/2000/XP
	�R���g���[���p�l���A�v���b�g/�N���X�C���X�g�[��
�@�@�@Copyright (c) 1999-2004 by *Error15
*/

/*�@�X�V����
	v1.00
		�V�K�쐬
	v1.01
		over32MB�Ή�(64MB�܂�)
	v1.10
		Windows2000�N���X�C���X�g�[���ǉ�
	v1.11
		Windows2000�v���p�e�B�V�[�g�y�[�W�ǉ�
		��y�[�W,�y�[�W�v�[���T�C�Y�ύX�@�\�ǉ�
	v2.00
		��y�[�W,�y�[�W�v�[���T�C�Y�ύX�@�\�p�~
		OS�Ǘ��O�������ݒ�@�\�ǉ�
		�A���C���X�g�[���@�\�ǉ�
	v2.01
		�A���P�[�V�������j�b�g32�𑝂₵��1GB�m�ۉ\�c
		�A���C���X�g�[���@�\��Windows2000�Ή������ɔ���NT3.51�Ή��p�~
	v2.02
		�h���C�u�������g�p���̏ꍇ�͌x�����o���悤�ɂ���
		�y�[�W����6���������͂ł��Ȃ������̂��C��
		MAXMEM=nn�ȍ~�̃������̊J�n�A�h���X���������݉\�ɂ���
		�폜�ナ�u�[�g�_�C�A���O���\������Ă��Ȃ������̂��C��
		NT�ō폜�����RAM�f�B�X�N���쐬����Ă����̂��C��
		�����������X�L�b�v���邩�ǂ����ۑ��\�ɂ���
		�X���b�v�t�@�C����������悤�ɂ��邩�ǂ����I���\�ɂ���
		NT3.51�Ή�����
		�ݒ�ύX�ヌ�W�X�g���̃h���C�u�������� : �������Ă����̂��C��
		�C�x���g���O���b�Z�[�W�폜�Ή�
	v2.10
		Win2000�ȍ~(=FAT32�Ή�)�̏ꍇ�͎����őΉ�bit��ݒ�
		�ő�A���P�[�V�������j�b�g64��
	v2.11
		WinXP�Ή�
		Fastfat�h���C�o�̃X�^�[�g�A�b�v�ύX�@�\�ǉ�
	v2.12
		������������o����UI���t�]
		�X�^���o�C�΍����ǉ�
	v2.20
		'�ɂ�'������C��
		�����񃊃\�[�X�č��Ή�
		16bitFAT�̍ő�N���X�^��65525�ɐ���
		���b�Z�[�W�{�b�N�X�����\�[�X�Ή�
		�I�v�V�����t���O��32bit��
		4GB�����ǉ�
		�X���b�v�֌W�������f�o�C�X�ݒ�\�ɂ���
		TEMP�f�B���N�g���쐬�̕ҏW�ǉ�
		���[�g�f�B���N�g�������m�F�ǉ�
*/


#define STRICT
#pragma warning(disable : 4001 4054 4055 4100 4115 4201 4214 4514)
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <prsht.h>
#include <cpl.h>
#include <regstr.h>
#include <setupapi.h>
#include <dbt.h>
#include "eramntui.h"

#define RAMDISK_MEDIA_TYPE		0xf8	/*�@ERAMNT.H�@*/
#define	SECTOR	(512)					/*�@ERAMNT.H�@*/
#define PAGE_SIZE_4K	(1024 * 4)		/*�@1�y�[�W�̑傫���@*/
#define	DISKMAXCLUSTER_16 (65525)		/*�@FAT16�̍ő�N���X�^�@*/
#define	DISKMAXCLUSTER_32 (268435455)	/*�@FAT32�̍ő�N���X�^�@*/
#define	DISKMINPAGE		(16)			/*�@�f�[�^�̈悪�m�ۂł��Ȃ�;�A���P�[�V����2�ł�2���ŏ��@*/
#define	MAXALLOCUNIT	(64)			/*�@�A���P�[�V�������j�b�g�@*/
#define	MAXINSTANCE		(9999)			/*�@�C���X�^���X�@*/
#define	LIMIT_4GBPAGES	(0xfffff)		/*�@4GB�y�[�W�@*/

#define	EXPORT	__declspec(dllexport)

#define SPPSR_ENUM_ADV_DEVICE_PROPERTIES   3

/*�@ERAM���W�X�g���ݒ�l�Q�Ɨp�\���́@*/
typedef union {
	DWORD	dwOptflag;					// ERAM����
	struct {
		BYTE	NonPaged:1;				// bit 0:NonPagedPool�g�p
		BYTE	External:1;				// bit 1:�O���������g�p
		BYTE	SkipExternalCheck:1;	// bit 2:�O���������g�p���������������Ȃ�
		BYTE	Swapable:1;				// bit 3:���[�J���f�B�X�N�Ƃ��Ĉ���
		BYTE	EnableFat32:1;			// bit 4:FAT32�̎g�p������
		BYTE	SkipReportUsage:1;		// bit 5:�O���������g�p��Report���Ȃ�=2000:�X�^���o�C��
		BYTE	MakeTempDir:1;			// bit 6:TEMP�f�B���N�g���쐬
		BYTE	byResv7:1;				// bit 7:
		BYTE	byResv8:8;				// bit 8:
		BYTE	byResv16:8;				// bit16:
		BYTE	byResv24:7;				// bit24:
		BYTE	UseExtFile:1;			// bit31:�O���t�@�C���g�p
	} Bits;
 } ERAM_OPTFLAG, *PERAM_OPTFLAG;

typedef struct {
	DWORD			dwSizePage;
	DWORD			dwExtStart;
	ERAM_OPTFLAG	uOption;
	WORD			wRootDir;
	BYTE			byAllocUnit;
	BYTE			byMediaId;
	CHAR			szDefDrv[3];
 } ERAMREGOPT, *PERAMREGOPT, FAR *LPERAMREGOPT;

/*�@SETUPAPI�֐��^��`�@*/
typedef HDEVINFO (WINAPI* LPFNSETUPDIGETCLASSDEVSA)(LPGUID, PCSTR, HWND, DWORD);
typedef BOOL (WINAPI* LPFNSETUPDIENUMDEVICEINFO)(HDEVINFO, DWORD, PSP_DEVINFO_DATA);
typedef BOOL (WINAPI* LPFNSETUPDIREMOVEDEVICE)(HDEVINFO, PSP_DEVINFO_DATA);
typedef BOOL (WINAPI* LPFNSETUPDIDESTROYDEVICEINFOLIST)(HDEVINFO);
typedef HKEY (WINAPI* LPFNSETUPDIOPENDEVREGKEY)(HDEVINFO, PSP_DEVINFO_DATA, DWORD, DWORD, DWORD, REGSAM);

/*�@ERAM���֐��|�C���^�@*/
typedef struct {
	HMODULE								hSetupApi;
	LPFNSETUPDIGETCLASSDEVSA			lpfnSetupDiGetClassDevs;
	LPFNSETUPDIENUMDEVICEINFO			lpfnSetupDiEnumDeviceInfo;
	LPFNSETUPDIREMOVEDEVICE				lpfnSetupDiRemoveDevice;
	LPFNSETUPDIDESTROYDEVICEINFOLIST	lpfnSetupDiDestroyDeviceInfoList;
	LPFNSETUPDIOPENDEVREGKEY			lpfnSetupDiOpenDevRegKey;
 } SETUPAPIENTRYS, FAR *LPSETUPAPIENTRYS, *PSETUPAPIENTRYS;

/*�@�O���[�o���ϐ��@*/
HINSTANCE hgInstance = NULL;
BOOL bUpdate = FALSE;
BOOL bReboot = FALSE;
HKEY hgKey = NULL;
BOOL bProp = FALSE;
SETUPAPIENTRYS sSetupApi = { NULL, NULL, NULL, NULL, NULL, NULL };

/*�@������萔�@*/
CHAR szWinName[] = "ERAM for Windows NT/2000/XP";
CHAR szRootDir[] = "RootDirEntries";
CHAR szOption[] = "Option";
CHAR szAllocUnit[] = "AllocUnit";
CHAR szMediaId[] = "MediaId";
CHAR szDefDrv[] = "DriveLetter";
CHAR szPage[] = "Page";
CHAR szExtStart[] = "ExtStart";

/*�@�v���g�^�C�v�@*/
BOOL WINAPI StatusDlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL WINAPI WmInitDialog(HWND, HWND, LPARAM);
VOID WINAPI GetRegOption(LPERAMREGOPT);
VOID WINAPI ReadRegValues(HKEY, LPSTR, UINT, LPVOID, ULONG, WORD);
VOID WINAPI SetPageOption(HWND, LPERAMREGOPT);
VOID WINAPI WmCommand(HWND, INT, HWND, UINT);
VOID WINAPI EnableExtGroup(HWND, BOOL);
VOID WINAPI Reboot(HWND);
BOOL WINAPI SettingUpdate(HWND);
BOOL WINAPI GetPageOption(HWND, LPERAMREGOPT);
BOOL WINAPI SetRegOption(LPERAMREGOPT);
LONG WINAPI CplInit(VOID);
VOID WINAPI CplNewInquire(LPNEWCPLINFO);
BOOL WINAPI SystemShutdown(VOID);
DWORD WINAPI WmNotify(HWND, INT, NMHDR FAR*);
VOID WINAPI WmDestroy(HWND);
BOOL WINAPI Eram2000UnInstall(HWND);
BOOL WINAPI GetInfName(HDEVINFO, PSP_DEVINFO_DATA, LPSTR, DWORD);
BOOL WINAPI DeleteInfFiles(LPCSTR);
LPCSTR WINAPI GetEramClass(GUID*);
LPSTR WINAPI GetResStr(WORD, LPSTR, INT);


/*�@StatusDlgProc
		�ݒ�_�C�A���O
	����
		hDlg		�_�C�A���O�̃E�B���h�E�n���h��
		uMsg		���b�Z�[�W
		wParam		����
		lParam		����
	�߂�l
		����
*/

BOOL WINAPI StatusDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	HANDLE_MSG(hDlg, WM_INITDIALOG	, WmInitDialog);	/*�@�_�C�A���O�쐬���@*/
	HANDLE_MSG(hDlg, WM_COMMAND		, WmCommand);		/*�@�R���g���[�����쎞�@*/
	HANDLE_MSG(hDlg, WM_NOTIFY		, WmNotify);		/*�@�ʒm���b�Z�[�W��M���@*/
	HANDLE_MSG(hDlg, WM_DESTROY		, WmDestroy);		/*�@����@*/
	}
	return FALSE;
}


/*�@WmInitDialog
		�_�C�A���O���������̏���
	����
		hDlg		�_�C�A���O�̃E�B���h�E�n���h��
		hwndFocus	�t�H�[�J�X���󂯎��R���g���[���̃n���h��
		lInitParam	����
	�߂�l
		����
*/

BOOL WINAPI WmInitDialog(HWND hDlg, HWND hwndFocus, LPARAM lInitParam)
{
	/*�@���[�J���ϐ��@*/
	DWORD dwDisp;
	ERAMREGOPT EramOpt;
	CHAR szPath[MAX_PATH], szText[128];
	/*�@�t���O�������@*/
	bUpdate = FALSE;
	bReboot = FALSE;
	/*�@�v���p�e�B�̂Ƃ��͕s�v�ȃ{�^�����B���@*/
	if (bProp != FALSE)
	{
		ShowWindow(GetDlgItem(hDlg, IDOK), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, IDCANCEL), SW_HIDE);
		ShowWindow(GetDlgItem(hDlg, IDC_UPDATE), SW_HIDE);
	}
	/*�@���W�X�g���L�[�I�[�v���@*/
	wsprintf(szPath, "%s\\Eram\\Parameters", REGSTR_PATH_SERVICES);
	if (RegCreateKeyEx(HKEY_LOCAL_MACHINE, szPath, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hgKey, &dwDisp) != ERROR_SUCCESS)	/*�@���s�@*/
	{
		MessageBox(hDlg, GetResStr(IDS_ERR_OPEN_REG, szText, sizeof(szText)), szWinName, MB_OK | MB_ICONEXCLAMATION | MB_SETFOREGROUND);
		EndDialog(hDlg, 0);
		return FALSE;
	}
	/*�@���W�X�g���l�擾�@*/
	GetRegOption(&EramOpt);
	/*�@���W�X�g���l���R���g���[���ɔ��f�@*/
	SetPageOption(hDlg, &EramOpt);
	return FALSE;
}


/*�@GetRegOption
		���W�X�g���ݒ�l�̎擾
	����
		lpEramOpt	ERAM_REGOPT�\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID WINAPI GetRegOption(LPERAMREGOPT lpEramOpt)
{
	/*�@���[�g�f�B���N�g�����擾�@*/
	ReadRegValues(hgKey, szRootDir, REG_DWORD, &(lpEramOpt->wRootDir), sizeof(lpEramOpt->wRootDir), 128);
	/*�@�I�v�V�����擾�@*/
	ReadRegValues(hgKey, szOption, REG_DWORD, &(lpEramOpt->uOption.dwOptflag), sizeof(lpEramOpt->uOption.dwOptflag), 0);
	/*�@�A���P�[�V�������j�b�g�擾�@*/
	ReadRegValues(hgKey, szAllocUnit, REG_DWORD, &(lpEramOpt->byAllocUnit), sizeof(lpEramOpt->byAllocUnit), 1024 / SECTOR);
	/*�@���f�B�AID�擾�@*/
	ReadRegValues(hgKey, szMediaId, REG_DWORD, &(lpEramOpt->byMediaId), sizeof(lpEramOpt->byMediaId), RAMDISK_MEDIA_TYPE);
	/*�@�h���C�u�����擾�@*/
	ReadRegValues(hgKey, szDefDrv, REG_SZ, lpEramOpt->szDefDrv, sizeof(lpEramOpt->szDefDrv), (WORD)'Z');
	lpEramOpt->szDefDrv[1] = '\0';
	/*�@�y�[�W���擾�@*/
	ReadRegValues(hgKey, szPage, REG_DWORD, &(lpEramOpt->dwSizePage), sizeof(lpEramOpt->dwSizePage), DISKMINPAGE);
	/*�@�O���������J�n�ʒu�擾�@*/
	ReadRegValues(hgKey, szExtStart, REG_DWORD, &(lpEramOpt->dwExtStart), sizeof(lpEramOpt->dwExtStart), 0);
}


/*�@ReadRegValues
		���W�X�g���̎擾�Ɗ���l�ݒ�
	����
		hKey			�A�N�Z�X����L�[
		lpszValueName	�l��������ւ̃|�C���^
		uType			�l�^�C�v REG_DWORD �܂��� REG_SZ
		lpVal			�l�擾�̈�ւ̃|�C���^
		uSizeOrg		�l�擾�̈�̃T�C�Y
		wDefVal			����l
	�߂�l
		�Ȃ�
*/

VOID WINAPI ReadRegValues(HKEY hKey, LPSTR lpszValueName, UINT uType, LPVOID lpVal, ULONG uSizeOrg, WORD wDefVal)
{
	/*�@���[�J���ϐ��@*/
	LONG lRet;
	ULONG uSize;
	DWORD dwVal, dwType;
	switch (uType)
	{
	case REG_DWORD:
		uSize = sizeof(dwVal);
		/*�@���W�X�g���l�擾�@*/
		lRet = RegQueryValueEx(hKey, lpszValueName, NULL, &dwType, (LPBYTE)(&dwVal), &uSize);
		if ((lRet == ERROR_SUCCESS)&&
			(dwType == uType))		/*�@�擾�����@*/
		{
			/*�@�擾�l��ݒ�@*/
			switch (uSizeOrg)
			{
			case sizeof(DWORD):
				*((LPDWORD)lpVal) = (DWORD)dwVal;
				return;
			case sizeof(WORD):
				*((LPWORD)lpVal) = (WORD)((dwVal > MAXWORD) ? MAXWORD : (WORD)dwVal);
				return;
			case sizeof(BYTE):
				*((LPBYTE)lpVal) = (BYTE)((dwVal > MAXBYTE) ? MAXBYTE : (BYTE)dwVal);
				return;
			}
		}
		break;
	case REG_SZ:
		uSize = uSizeOrg;
		/*�@���W�X�g���l�擾�@*/
		lRet = RegQueryValueEx(hKey, lpszValueName, NULL, &dwType, lpVal, &uSize);
		if ((lRet == ERROR_SUCCESS)&&
			(dwType == uType))		/*�@�擾�����@*/
		{
			return;
		}
		break;
	}
	/*�@����l��ݒ�@*/
	switch (uSizeOrg)
	{
	case sizeof(DWORD):
		*((LPDWORD)lpVal) = (DWORD)wDefVal;
		break;
	case sizeof(WORD):
		*((LPWORD)lpVal) = wDefVal;
		break;
	case sizeof(BYTE):
		*((LPBYTE)lpVal) = (BYTE)wDefVal;
		break;
	}
}


/*�@SetPageOption
		���W�X�g���l���R���g���[���ɔ��f
	����
		hDlg		�_�C�A���O�̃E�B���h�E�n���h��
		lpEramOpt	ERAM_REGOPT�\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID WINAPI SetPageOption(HWND hDlg, LPERAMREGOPT lpEramOpt)
{
	/*�@���[�J���ϐ��@*/
	CHAR szId[3], szDrv[2], szAlloc[3];
	HWND hCtl;
	UINT loopi, uAlloc;
	CHAR cDrv;
	INT nSelect;
	/*�@���[�g�f�B���N�g�����ݒ�@*/
	SetDlgItemInt(hDlg, IDC_EDIT_ROOTDIR, (UINT)(lpEramOpt->wRootDir), FALSE);
	Edit_LimitText(GetDlgItem(hDlg, IDC_EDIT_ROOTDIR), 4);	/*�@�ő�9999�@*/
	/*�@�I�v�V�����ݒ�@*/
	if (lpEramOpt->uOption.Bits.NonPaged != 0)
	{
		Button_SetCheck(GetDlgItem(hDlg, IDC_RADIO_NONPAGED), 1);
		EnableExtGroup(hDlg, FALSE);
	}
	else if (lpEramOpt->uOption.Bits.External != 0)
	{
		Button_SetCheck(GetDlgItem(hDlg, IDC_RADIO_EXTERNAL), 1);
		EnableExtGroup(hDlg, TRUE);
	}
	else
	{
		Button_SetCheck(GetDlgItem(hDlg, IDC_RADIO_PAGED), 1);
		EnableExtGroup(hDlg, FALSE);
	}
	if (lpEramOpt->uOption.Bits.SkipExternalCheck == 0)
	{
		Button_SetCheck(GetDlgItem(hDlg, IDC_CHECK_NOTSEARCHSKIP), 1);
	}
	if (lpEramOpt->uOption.Bits.Swapable != 0)
	{
		Button_SetCheck(GetDlgItem(hDlg, IDC_CHECK_LOCAL_DISK), 1);
	}
	if (lpEramOpt->uOption.Bits.SkipReportUsage == 0)
	{
		Button_SetCheck(GetDlgItem(hDlg, IDC_CHECK_REPORTUSAGE), 1);
	}
	if (lpEramOpt->uOption.Bits.MakeTempDir != 0)
	{
		Button_SetCheck(GetDlgItem(hDlg, IDC_CHECK_MAKE_TEMP), 1);
	}
	/*�@�A���P�[�V�������j�b�g�ݒ�@*/
	hCtl = GetDlgItem(hDlg, IDC_COMBO_ALLOCUNIT);
	nSelect = -1;
	for (loopi=0, uAlloc=1; uAlloc<=MAXALLOCUNIT; loopi++, uAlloc<<=1)
	{
		if (lpEramOpt->byAllocUnit == uAlloc)
		{
			nSelect = loopi;
		}
		wsprintf((LPSTR)szAlloc, "%d", uAlloc);
		ComboBox_AddString(hCtl, (LPSTR)szAlloc);
	}
	if (nSelect < 0)
	{
		nSelect = 1;	/*�@2�@*/
	}
	ComboBox_SetCurSel(hCtl, nSelect);
	/*�@���f�B�AID�ݒ�@*/
	wsprintf((LPSTR)szId, "%X", (UINT)(lpEramOpt->byMediaId));
	hCtl = GetDlgItem(hDlg, IDC_EDIT_MEDIAID);
	Edit_SetText(hCtl, (LPSTR)szId);
	Edit_LimitText(hCtl, sizeof(szId)-1);
	/*�@�h���C�u�����ݒ�@*/
	hCtl = GetDlgItem(hDlg, IDC_COMBO_DRIVE);
	nSelect = -1;
	lpEramOpt->szDefDrv[0] &= ~0x20;
	szDrv[1] = '\0';
	for (loopi=0, cDrv='A'; cDrv<='Z'; loopi++, cDrv++)
	{
		if (lpEramOpt->szDefDrv[0] == cDrv)
		{
			nSelect = loopi;
		}
		szDrv[0] = cDrv;
		ComboBox_AddString(hCtl, (LPSTR)szDrv);
	}
	if (nSelect < 0)
	{
		nSelect = loopi - 1;	/*�@Z�@*/
	}
	ComboBox_SetCurSel(hCtl, nSelect);
	/*�@�y�[�W���ݒ�@*/
	SetDlgItemInt(hDlg, IDC_EDIT_PAGE, (ULONG)(lpEramOpt->dwSizePage << 2), FALSE);
	Edit_LimitText(GetDlgItem(hDlg, IDC_EDIT_PAGE), 7);		/*�@1024MB=1048576KB�@*/
	/*�@�O���������J�n�ʒu�ݒ�@*/
	hCtl = GetDlgItem(hDlg, IDC_EDIT_EXTSTART_MB);
	SetDlgItemInt(hDlg, IDC_EDIT_EXTSTART_MB, (ULONG)(lpEramOpt->dwExtStart / 0x100000), FALSE);
	Edit_LimitText(hCtl, 4);		/*�@4095MB�@*/
	if ((lpEramOpt->dwExtStart / 0x100000) != 0)		/*�@�w�肠��@*/
	{
		Button_SetCheck(GetDlgItem(hDlg, IDC_CHECK_EXTSTART), 1);
	}
	EnableExtGroup(hDlg, (lpEramOpt->uOption.Bits.External != 0) ? TRUE : FALSE);
}


/*�@WmCommand
		�R���g���[������
	����
		hDlg		�_�C�A���O�̃E�B���h�E�n���h��
		wId			����ID
		hWndCtl		�R���g���[���̃n���h��
		wNotifyCode	�ʒm�R�[�h
	�߂�l
		�Ȃ�
*/

VOID WINAPI WmCommand(HWND hDlg, INT wId, HWND hWndCtl, UINT wNotifyCode)
{
	/*�@�ύX�����������Ƃ��ɂ�����L�^�@*/
	switch (wId)
	{
	case IDC_COMBO_DRIVE:
	case IDC_COMBO_ALLOCUNIT:
		if (wNotifyCode == CBN_SELCHANGE)
		{
			bUpdate = TRUE;
		}
		break;
	case IDC_EDIT_ROOTDIR:
	case IDC_EDIT_MEDIAID:
	case IDC_EDIT_PAGE:
	case IDC_EDIT_EXTSTART_MB:
		if (wNotifyCode == EN_CHANGE)
		{
			bUpdate = TRUE;
		}
		break;
	case IDC_RADIO_PAGED:
		if (wNotifyCode == BN_CLICKED)
		{
			bUpdate = TRUE;
			EnableExtGroup(hDlg, FALSE);
		}
		break;
	case IDC_RADIO_NONPAGED:
		if (wNotifyCode == BN_CLICKED)
		{
			bUpdate = TRUE;
			EnableExtGroup(hDlg, FALSE);
		}
		break;
	case IDC_RADIO_EXTERNAL:
		if (wNotifyCode == BN_CLICKED)
		{
			bUpdate = TRUE;
			EnableExtGroup(hDlg, TRUE);
		}
		break;
	case IDC_CHECK_LOCAL_DISK:
	case IDC_CHECK_NOTSEARCHSKIP:
	case IDC_CHECK_MAKE_TEMP:
		if (wNotifyCode == BN_CLICKED)
		{
			bUpdate = TRUE;
		}
		break;
	case IDC_UPDATE:
		if (bProp != FALSE)
		{
			break;
		}
		SettingUpdate(hDlg);
		break;
	case IDOK:
		if (bProp != FALSE)
		{
			break;
		}
		if (SettingUpdate(hDlg) == FALSE)
		{
			break;
		}
	case IDCANCEL:
		if (bProp != FALSE)
		{
			break;
		}
		EndDialog(hDlg, 0);
		if (hgKey != NULL)
		{
			RegCloseKey(hgKey);
			hgKey = NULL;
		}
		/*�@���u�[�g�@*/
		Reboot(hDlg);
		break;
	case IDC_CHECK_EXTSTART:
		if (wNotifyCode == BN_CLICKED)
		{
			bUpdate = TRUE;
		}
		Edit_Enable(GetDlgItem(hDlg, IDC_EDIT_EXTSTART_MB), (Button_GetCheck(hWndCtl) != 0) ? TRUE : FALSE);
		break;
	}
}


/*�@EnableExtGroup
		OS�Ǘ��O�������̎g�p��/�s����
	����
		hDlg		�_�C�A���O�̃E�B���h�E�n���h��
		bEnable		�ݒ�\�ɂ��邩�ǂ���
	�߂�l
		�Ȃ�
*/

VOID WINAPI EnableExtGroup(HWND hDlg, BOOL bEnable)
{
	/*�@���[�J���ϐ��@*/
	HWND hCtl;
	Static_Enable(GetDlgItem(hDlg, IDC_STATIC_EXT), bEnable);
	Button_Enable(GetDlgItem(hDlg, IDC_CHECK_NOTSEARCHSKIP), bEnable);
	Button_Enable(GetDlgItem(hDlg, IDC_CHECK_REPORTUSAGE), bEnable);
	hCtl = GetDlgItem(hDlg, IDC_CHECK_EXTSTART);
	Button_Enable(hCtl, bEnable);
	if ((bEnable != FALSE)&&				/*�@���ꂩ��L�����@*/
		(Button_GetCheck(hCtl) == 0))		/*�@�w��Ȃ��@*/
	{
		bEnable = FALSE;
	}
	Edit_Enable(GetDlgItem(hDlg, IDC_EDIT_EXTSTART_MB), bEnable);
	Static_Enable(GetDlgItem(hDlg, IDC_STATIC_EXTSTART_MB), bEnable);
}


/*�@Reboot
		���u�[�g����
	����
		hDlg		�_�C�A���O�̃E�B���h�E�n���h��
	�߂�l
		�Ȃ�
*/

VOID WINAPI Reboot(HWND hDlg)
{
	/*�@���[�J���ϐ��@*/
	CHAR szText[128];
	if (bReboot == FALSE)
	{
		return;
	}
	if (MessageBox(hDlg, GetResStr(IDS_PROMPT_REBOOT, szText, sizeof(szText)), szWinName, MB_YESNO | MB_ICONQUESTION | MB_SETFOREGROUND) != IDYES)
	{
		return;
	}
	if (SystemShutdown() == FALSE)
	{
		MessageBox(hDlg, GetResStr(IDS_ERR_REBOOT, szText, sizeof(szText)), szWinName, MB_OK | MB_ICONEXCLAMATION | MB_SETFOREGROUND);
	}
	bReboot = FALSE;
}


/*�@SettingUpdate
		�ݒ�X�V����
	����
		hDlg		�_�C�A���O�̃E�B���h�E�n���h��
		wId			����ID
		hWndCtl		�R���g���[���̃n���h��
		wNotifyCode	�ʒm�R�[�h
	�߂�l
		����
*/

BOOL WINAPI SettingUpdate(HWND hDlg)
{
	/*�@���[�J���ϐ��@*/
	ERAMREGOPT EramOpt;
	CHAR szText[128];
	if (bUpdate == FALSE)		/*�@�X�V�����@*/
	{
		return TRUE;
	}
	/*�@��ʏ��擾�@*/
	if (GetPageOption(hDlg, &EramOpt) == FALSE)
	{
		return FALSE;
	}
	/*�@�ݒ���X�V�@*/
	if (SetRegOption(&EramOpt) == FALSE)
	{
		MessageBox(hDlg, GetResStr(IDS_ERR_REG_MODIFY, szText, sizeof(szText)), szWinName, MB_OK | MB_ICONEXCLAMATION | MB_SETFOREGROUND);
		return FALSE;
	}
	/*�@�ċN�����K�v�Ȃ��Ƃ��Z�b�g�@*/
	bReboot = TRUE;
	bUpdate = FALSE;
	return TRUE;
}


/*�@GetPageOption
		��ʏ��擾
	����
		hDlg		�_�C�A���O�̃E�B���h�E�n���h��
		lpEramOpt	ERAM_REGOPT�\���̂ւ̃|�C���^
	�߂�l
		����
*/

BOOL WINAPI GetPageOption(HWND hDlg, LPERAMREGOPT lpEramOpt)
{
	/*�@���[�J���ϐ��@*/
	CHAR szId[3], szRoot[4], szMsg[128], szVolLabel[16], szText[128];
	PSTR pEnd;
	ULONGLONG ulPageT;
	OSVERSIONINFO Ver;
	/*�@���[�g�f�B���N�g�����擾�@*/
	lpEramOpt->wRootDir = (WORD)GetDlgItemInt(hDlg, IDC_EDIT_ROOTDIR, NULL, FALSE);
	/*�@�I�v�V�����擾�@*/
	lpEramOpt->uOption.dwOptflag = 0;
	if (Button_GetCheck(GetDlgItem(hDlg, IDC_RADIO_NONPAGED)) != 0)
	{
		lpEramOpt->uOption.Bits.NonPaged = 1;
	}
	else if (Button_GetCheck(GetDlgItem(hDlg, IDC_RADIO_EXTERNAL)) != 0)
	{
		lpEramOpt->uOption.Bits.External = 1;
	}
	if (Button_GetCheck(GetDlgItem(hDlg, IDC_CHECK_NOTSEARCHSKIP)) == 0)
	{
		lpEramOpt->uOption.Bits.SkipExternalCheck = 1;
	}
	if (Button_GetCheck(GetDlgItem(hDlg, IDC_CHECK_LOCAL_DISK)) != 0)
	{
		lpEramOpt->uOption.Bits.Swapable = 1;
	}
	if (Button_GetCheck(GetDlgItem(hDlg, IDC_CHECK_REPORTUSAGE)) == 0)
	{
		lpEramOpt->uOption.Bits.SkipReportUsage = 1;
	}
	if (Button_GetCheck(GetDlgItem(hDlg, IDC_CHECK_MAKE_TEMP)) != 0)
	{
		lpEramOpt->uOption.Bits.MakeTempDir = 1;
	}
	Ver.dwOSVersionInfoSize = sizeof(Ver);
	if ((GetVersionEx(&Ver) != FALSE)&&
		(Ver.dwPlatformId == VER_PLATFORM_WIN32_NT)&&
		(Ver.dwMajorVersion >= 5))		/*�@Win2000�ȍ~�@*/
	{
		lpEramOpt->uOption.Bits.EnableFat32 = 1;
	}
	/*�@�A���P�[�V�������j�b�g�擾�@*/
	lpEramOpt->byAllocUnit = (BYTE)GetDlgItemInt(hDlg, IDC_COMBO_ALLOCUNIT, NULL, FALSE);
	/*�@���f�B�AID�擾�@*/
	Edit_GetText(GetDlgItem(hDlg, IDC_EDIT_MEDIAID), (LPSTR)szId, sizeof(szId));
	lpEramOpt->byMediaId = (BYTE)strtoul(szId, &pEnd, 16);
	/*�@�h���C�u�����擾�@*/
	ComboBox_GetText(GetDlgItem(hDlg, IDC_COMBO_DRIVE), (LPSTR)(lpEramOpt->szDefDrv), sizeof(lpEramOpt->szDefDrv));
	if (lpEramOpt->szDefDrv[0] != '\0')
	{
		if ((GetLogicalDrives() & (1 << (lpEramOpt->szDefDrv[0] - 'A'))) != 0)	/*�@���ݎg�p���@*/
		{
			wsprintf(szRoot, "%c:\\", lpEramOpt->szDefDrv[0]);
			switch (GetDriveType(szRoot))
			{
			case DRIVE_REMOTE:		/*�@�����[�g�@*/
			case DRIVE_RAMDISK:		/*�@�����炭���g�@*/
				break;
			default:				/*�@HDD���ŗ��p���@*/
				if ((GetVolumeInformation(szRoot, szVolLabel, sizeof(szVolLabel), NULL, NULL, NULL, NULL, 0) == FALSE)||
					(lstrcmpi(szVolLabel, "ERAM-DRIVE") != 0))
				{
					wsprintf(szMsg, GetResStr(IDS_WARN_DRV_USING, szText, sizeof(szText)), lpEramOpt->szDefDrv[0]);
					if (MessageBox(hDlg, szMsg, szWinName, MB_OKCANCEL | MB_ICONQUESTION | MB_SETFOREGROUND) != IDOK)
					{
						return FALSE;
					}
				}
				break;
			}
		}
	}
	/*�@�y�[�W���擾�@*/
	lpEramOpt->dwSizePage = (GetDlgItemInt(hDlg, IDC_EDIT_PAGE, NULL, FALSE) + 3) >> 2;
	if (lpEramOpt->uOption.Bits.EnableFat32 == 0)		/*�@FAT32�֎~�@*/
	{
		ulPageT = ((ULONGLONG)DISKMAXCLUSTER_16 * SECTOR * lpEramOpt->byAllocUnit) / PAGE_SIZE_4K;
	}
	else		/*�@FAT32�@*/
	{
		ulPageT = ((ULONGLONG)DISKMAXCLUSTER_32 * SECTOR * lpEramOpt->byAllocUnit) / PAGE_SIZE_4K;
	}
	if ((ULONGLONG)(lpEramOpt->dwSizePage) > ulPageT)		/*�@�A���P�[�V�������j�b�g�������߁@*/
	{
		lpEramOpt->dwSizePage = (DWORD)ulPageT;
		wsprintf(szMsg, GetResStr((WORD)((lpEramOpt->byAllocUnit == MAXALLOCUNIT) ? IDS_WARN_LIMIT_SIZE : IDS_WARN_LIMIT_SIZE_THIS_UNIT), szText, sizeof(szText)), ((DWORD)ulPageT << 2));
		MessageBox(hDlg, szMsg, szWinName, MB_OK | MB_ICONEXCLAMATION | MB_SETFOREGROUND);
		SetDlgItemInt(hDlg, IDC_EDIT_PAGE, ((DWORD)ulPageT << 2), FALSE);
		return FALSE;
	}
	/*�@4GB�`�F�b�N�@*/
	if (lpEramOpt->dwSizePage > LIMIT_4GBPAGES)
	{
		lpEramOpt->dwSizePage = LIMIT_4GBPAGES;
		wsprintf(szMsg, GetResStr(IDS_WARN_LIMIT_MAX_SIZE, szText, sizeof(szText)), (LIMIT_4GBPAGES << 2));
		MessageBox(hDlg, szMsg, szWinName, MB_OK | MB_ICONEXCLAMATION | MB_SETFOREGROUND);
		SetDlgItemInt(hDlg, IDC_EDIT_PAGE, (LIMIT_4GBPAGES << 2), FALSE);
		return FALSE;
	}
	/*�@���[�g�f�B���N�g���G���g���������@*/
	if (lpEramOpt->dwSizePage <= (DWORD)(((lpEramOpt->wRootDir * 32) + (PAGE_SIZE_4K - 1)) / PAGE_SIZE_4K))
	{
		MessageBox(hDlg, GetResStr(IDS_WARN_LIMIT_ROOTDIR, szText, sizeof(szText)), szWinName, MB_OK | MB_ICONEXCLAMATION | MB_SETFOREGROUND);
		SetDlgItemInt(hDlg, IDC_EDIT_ROOTDIR, 128, FALSE);
		return FALSE;
	}
	/*�@�O���������J�n�ʒu�擾�@*/
	lpEramOpt->dwExtStart = 0;
	if (Button_GetCheck(GetDlgItem(hDlg, IDC_CHECK_EXTSTART)) != 0)
	{
		lpEramOpt->dwExtStart = GetDlgItemInt(hDlg, IDC_EDIT_EXTSTART_MB, NULL, FALSE) * 0x100000;
	}
	return TRUE;
}


/*�@SetRegOption
		�ݒ���X�V
	����
		lpEramOpt	ERAM_REGOPT�\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

BOOL WINAPI SetRegOption(LPERAMREGOPT lpEramOpt)
{
	/*�@���[�J���ϐ��@*/
	DWORD dwVal;
	/*�@���[�g�f�B���N�g�����ݒ�@*/
	dwVal = (DWORD)lpEramOpt->wRootDir;
	if (RegSetValueEx(hgKey, szRootDir, 0, REG_DWORD, (LPBYTE)(&dwVal), sizeof(dwVal)) != ERROR_SUCCESS)
	{
		return FALSE;
	}
	/*�@�I�v�V�����ݒ�@*/
	dwVal = (DWORD)lpEramOpt->uOption.dwOptflag;
	if (RegSetValueEx(hgKey, szOption, 0, REG_DWORD, (LPBYTE)(&dwVal), sizeof(dwVal)) != ERROR_SUCCESS)
	{
		return FALSE;
	}
	/*�@�A���P�[�V�������j�b�g�ݒ�@*/
	dwVal = (DWORD)lpEramOpt->byAllocUnit;
	if (RegSetValueEx(hgKey, szAllocUnit, 0, REG_DWORD, (LPBYTE)(&dwVal), sizeof(dwVal)) != ERROR_SUCCESS)
	{
		return FALSE;
	}
	/*�@���f�B�AID�ݒ�@*/
	dwVal = (DWORD)lpEramOpt->byMediaId;
	if (RegSetValueEx(hgKey, szMediaId, 0, REG_DWORD, (LPBYTE)(&dwVal), sizeof(dwVal)) != ERROR_SUCCESS)
	{
		return FALSE;
	}
	/*�@�h���C�u�����ݒ�@*/
	lpEramOpt->szDefDrv[1] = ':';
	lpEramOpt->szDefDrv[2] = '\0';
	if (RegSetValueEx(hgKey, szDefDrv, 0, REG_SZ, (LPBYTE)(lpEramOpt->szDefDrv), sizeof(lpEramOpt->szDefDrv)) != ERROR_SUCCESS)
	{
		return FALSE;
	}
	/*�@�y�[�W���ݒ�@*/
	if (RegSetValueEx(hgKey, szPage, 0, REG_DWORD, (LPBYTE)(&(lpEramOpt->dwSizePage)), sizeof(lpEramOpt->dwSizePage)) != ERROR_SUCCESS)
	{
		return FALSE;
	}
	/*�@�O���������J�n�ʒu�ݒ�@*/
	if (RegSetValueEx(hgKey, szExtStart, 0, REG_DWORD, (LPBYTE)(&(lpEramOpt->dwExtStart)), sizeof(lpEramOpt->dwExtStart)) != ERROR_SUCCESS)
	{
		return FALSE;
	}
	return TRUE;
}


/*�@CPlApplet
		�R���g���[���p�l���A�v���b�g
	����
		hwndCPL		�R���g���[���p�l���e�E�B���h�E�̃n���h��
		uMsg		�ʒm���b�Z�[�W
		lParam1		�p�����[�^1
		lParam2		�p�����[�^2
	�߂�l
		����
*/

LONG __declspec(dllexport) CALLBACK CPlApplet(HWND hwndCPL, UINT uMsg, LPARAM lParam1, LPARAM lParam2)
{
	switch (uMsg)
	{
	case CPL_INIT:			/*�@���������b�Z�[�W�@*/
		return CplInit();
	case CPL_GETCOUNT:		/*�@�_�C�A���O�{�b�N�X���擾�v���@*/
		return 1;
	case CPL_NEWINQUIRE:	/*�@�_�C�A���O�{�b�N�X���擾�v���@*/
		CplNewInquire((LPNEWCPLINFO)lParam2);
		break;
	case CPL_SELECT:
		break;
	case CPL_DBLCLK:	/*�@�_�u���N���b�N���ꂽ�@*/
		/*�@�_�C�A���O�\���@*/
		DialogBox(hgInstance, MAKEINTRESOURCE(IDD_SETUP), hwndCPL, StatusDlgProc);
		break;
	case CPL_STOP:
		break;
	case CPL_EXIT:
		break;
	default:
		break;
	}
	return 0;
}


/*	CplInit
		�R���g���[���p�l���A�v���b�g:������
	����
		�Ȃ�
	�߂�l
		����
*/

LONG WINAPI CplInit(VOID)
{
	/*�@���[�J���ϐ��@*/
	OSVERSIONINFO Ver;
	Ver.dwOSVersionInfoSize = sizeof(Ver);
	if (GetVersionEx(&Ver) == FALSE)
	{
		return FALSE;
	}
	/*�@NT�ȊO�̓��[�h���Ȃ��@*/
	if (Ver.dwPlatformId != VER_PLATFORM_WIN32_NT)
	{
		return FALSE;
	}
	return TRUE;
}


/*�@�_�C�A���O�{�b�N�X���擾�v���@*/
/*	CplNewInquire
		�R���g���[���p�l���A�v���b�g:�_�C�A���O�{�b�N�X���擾�v��
	����
		lpNewCPlInfo	���\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID WINAPI CplNewInquire(LPNEWCPLINFO lpNewCPlInfo)
{
	/*�@����Ԃ��@*/
	ZeroMemory(lpNewCPlInfo, sizeof(*lpNewCPlInfo));
	lpNewCPlInfo->dwSize = sizeof(*lpNewCPlInfo);
	lpNewCPlInfo->hIcon = LoadIcon(hgInstance, MAKEINTRESOURCE(IDI_ICON));
	lstrcpy(lpNewCPlInfo->szName, "ERAM");
	GetResStr(IDS_INFO_DESC, lpNewCPlInfo->szInfo, sizeof(lpNewCPlInfo->szInfo));
}


/*	SystemShutdown
		���u�[�g�w��
	����
		�Ȃ�
	�߂�l
		����
*/

BOOL WINAPI SystemShutdown(VOID)
{
	/*�@���[�J���ϐ��̒�`�@*/
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	/*�@�V���b�g�_�E��������L���ɂ���@*/
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken) == FALSE)
	{
		return FALSE;
	}
	/*�@LUID�擾�@*/
	LookupPrivilegeValue("", SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	/*�@�V���b�g�_�E�������L�����@*/
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	if (GetLastError() != ERROR_SUCCESS)		/*�@�L�������s�@*/
	{
		CloseHandle(hToken);
		return FALSE;
	}
	/*�@�V���b�g�_�E���w���@*/
	if (ExitWindowsEx(EWX_REBOOT, 0) == FALSE)
	{
		CloseHandle(hToken);
		return FALSE;
	}
	/*�@�V���b�g�_�E�������������@*/
	tkp.Privileges[0].Attributes = 0;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	CloseHandle(hToken);
	return TRUE;
}


/*�@WmNotify
		�ʒm���b�Z�[�W����
	����
		hDlg		�_�C�A���O�̃E�B���h�E�n���h��
		idFrom		����ID
		pnmhdr		�ʒm���
	�߂�l
		����
*/

DWORD WINAPI WmNotify(HWND hDlg, INT idFrom, NMHDR FAR* pnmhdr)
{
	if (pnmhdr->code == PSN_APPLY)	/*�@�K�p�@*/
	{
		/*�@�X�V�@*/
		if (SettingUpdate(hDlg) == FALSE)
		{
			SetWindowLong(hDlg, DWL_MSGRESULT, PSNRET_INVALID_NOCHANGEPAGE);
			return TRUE;
		}
		/*�@���u�[�g���K�v�Ȃ烊�u�[�g����@*/
		Reboot(hDlg);
		SetWindowLong(hDlg, DWL_MSGRESULT, PSNRET_NOERROR);
		return TRUE;
	}
	return FORWARD_WM_NOTIFY(hDlg, idFrom, pnmhdr, DefWindowProc);
}


/*�@WmDestroy
		�j�����b�Z�[�W����
	����
		hDlg		�_�C�A���O�̃E�B���h�E�n���h��
	�߂�l
		�Ȃ�
*/

VOID WINAPI WmDestroy(HWND hDlg)
{
	if (hgKey != NULL)
	{
		RegCloseKey(hgKey);
		hgKey = NULL;
	}
	FORWARD_WM_DESTROY(hDlg, DefWindowProc);
}


/*�@EramClassInstall
		�N���X�C���X�g�[��
	����
		diFctn			�@�\�ԍ�
		hDevInfoSet		�f�o�C�X���̃n���h��
		pDevInfoData	�f�o�C�X���ւ̃|�C���^
	�߂�l
		����
*/

DWORD EXPORT WINAPI EramClassInstall(DI_FUNCTION diFctn, HDEVINFO hDevInfoSet, PSP_DEVINFO_DATA pDevInfoData)
{
	/*�@�f�t�H���g���삳����@*/
	return ERROR_DI_DO_DEFAULT;
}


/*�@EnumPropPages32
		�v���p�e�B�y�[�W�v���o�C�_
	����
		lplDi		�f�o�C�X���ւ̃|�C���^
		lpfnAddPage	�y�[�W�ǉ��֐��|�C���^
		lParam		����
	�߂�l
		����
*/

BOOL EXPORT WINAPI EnumPropPages32(PSP_PROPSHEETPAGE_REQUEST pInfo, LPFNADDPROPSHEETPAGE lpfnAddPage, LPARAM lParam)
{
	/*�@���[�J���ϐ��@*/
	PROPSHEETPAGE Setting;
	HPROPSHEETPAGE hSetting;
	CHAR szText[64];
	if (pInfo->PageRequested == SPPSR_ENUM_ADV_DEVICE_PROPERTIES)
	{
		bProp = TRUE;
		/*�@�y�[�W��p�Ӂ@*/
		ZeroMemory(&Setting, sizeof(Setting));
		Setting.dwSize = sizeof(Setting);
		Setting.dwFlags = PSP_USETITLE;
		Setting.hInstance = hgInstance;
		Setting.pszTemplate = MAKEINTRESOURCE(IDD_SETUP);
		Setting.pszTitle = GetResStr(IDS_TAB_TITLE, szText, sizeof(szText));
		Setting.pfnDlgProc = (DLGPROC)StatusDlgProc;
		/*�@�y�[�W���쐬�@*/
		hSetting = CreatePropertySheetPage(&Setting);
		if (hSetting == NULL)		/*�@�쐬���s�@*/
		{
			/*�@������Ԃ��@*/
			return TRUE;
		}
		/*�@�y�[�W��ǉ��@*/
		if ((*lpfnAddPage)(hSetting, lParam) == FALSE)	/*�@�ǉ����s�@*/
		{
			DestroyPropertySheetPage(hSetting);
		}
	}
	return TRUE;
}


/*�@EramUninstall
		�A���C���X�g�[��
	����
		hWnd		�e�E�B���h�E�n���h��
		hInstance	�C���X�^���X�n���h��
		lpszCmdLine	����
		nCmdShow	�\�����
	�߂�l
		�Ȃ�
*/

VOID EXPORT CALLBACK EramUninstall(HWND hWnd, HINSTANCE hInstance, LPSTR lpszCmdLine, INT nCmdShow)
{
	/*�@���[�J���ϐ��@*/
	SC_HANDLE hScm, hEram;
	CHAR szMsg[256], szSysDir[MAX_PATH], szFile[MAX_PATH], szText[128];
	DWORD dwError;
	OSVERSIONINFO Ver;
	if (MessageBox(hWnd, GetResStr(IDS_PROMPT_ERAM_REMOVE, szText, sizeof(szText)), szWinName, MB_OKCANCEL) != IDOK)
	{
		return;
	}
	Ver.dwOSVersionInfoSize = sizeof(Ver);
	if ((GetVersionEx(&Ver) == FALSE)||
		(Ver.dwPlatformId != VER_PLATFORM_WIN32_NT))	/*�@NT�ȊO�@*/
	{
		MessageBox(hWnd, GetResStr(IDS_ERR_DETECT_OS, szText, sizeof(szText)), szWinName, MB_OK);
		return;
	}
	if (Ver.dwMajorVersion >= 5)		/*�@Windows2000�@*/
	{
		/*�@�f�o�C�X�}�l�[�W������̍폜�����@*/
		if (Eram2000UnInstall(hWnd) == FALSE)
		{
			MessageBox(hWnd, GetResStr(IDS_PROMPT_BEFORE_DEVMGR, szText, sizeof(szText)), szWinName, MB_OK);
			return;
		}
	}
	/*�@SCM�ڑ��@*/
	hScm = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (hScm == NULL)
	{
		dwError = GetLastError();
		if (dwError == ERROR_ACCESS_DENIED)
		{
			MessageBox(hWnd, GetResStr(IDS_ERR_NEED_REMOVE_PRIV, szText, sizeof(szText)), szWinName, MB_OK);
			return;
		}
		wsprintf(szMsg, GetResStr(IDS_ERR_OPEN_SCM, szText, sizeof(szText)), dwError);
		MessageBox(hWnd, szMsg, szWinName, MB_OK);
		return;
	}
	/*�@ERAM�f�o�C�X�I�[�v���@*/
	hEram = OpenService(hScm, "Eram", SERVICE_CHANGE_CONFIG | DELETE);
	if (hEram == NULL)
	{
		dwError = GetLastError();
		if (dwError != ERROR_SERVICE_DOES_NOT_EXIST)		/*�@�A���C���X�g�[���ς݈ȊO�@*/
		{
			wsprintf(szMsg, GetResStr(IDS_ERR_OPEN_ERAM, szText, sizeof(szText)), dwError);
			MessageBox(hWnd, szMsg, szWinName, MB_OK);
			CloseServiceHandle(hScm);
			return;
		}
	}
	else
	{
		/*�@�X�^�[�g�A�b�v�ŋN�����Ă��Ȃ��悤�ύX�@*/
		ChangeServiceConfig(hEram, SERVICE_NO_CHANGE, SERVICE_DISABLED, SERVICE_NO_CHANGE, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
		/*�@ERAM�f�o�C�X�폜�@*/
		if (DeleteService(hEram) == FALSE)
		{
			wsprintf(szMsg, GetResStr(IDS_ERR_ERAM_REMOVE, szText, sizeof(szText)), GetLastError());
			MessageBox(hWnd, szMsg, szWinName, MB_OK);
			CloseServiceHandle(hEram);
			return;
		}
		CloseServiceHandle(hEram);
	}
	CloseServiceHandle(hScm);
	if (GetSystemDirectory(szSysDir, sizeof(szSysDir)) == 0)
	{
		wsprintf(szMsg, GetResStr(IDS_ERR_GET_SYSDIR, szText, sizeof(szText)), GetLastError());
		MessageBox(hWnd, szMsg, szWinName, MB_OK);
		return;
	}
	/*�@ERAM�폜�@*/
	wsprintf(szFile, "%s\\drivers\\eram.sys", szSysDir);
	if (MoveFileEx(szFile, NULL, MOVEFILE_DELAY_UNTIL_REBOOT) == FALSE)
	{
		wsprintf(szMsg, GetResStr(IDS_ERR_REMOVE, szText, sizeof(szText)), szFile, GetLastError());
		MessageBox(hWnd, szMsg, szWinName, MB_OK);
	}
	/*�@�R���g���[���p�l���폜�@*/
	wsprintf(szFile, "%s\\eramnt.cpl", szSysDir);
	if (MoveFileEx(szFile, NULL, MOVEFILE_DELAY_UNTIL_REBOOT) == FALSE)
	{
		wsprintf(szMsg, GetResStr(IDS_ERR_REMOVE, szText, sizeof(szText)), szFile, GetLastError());
		MessageBox(hWnd, szMsg, szWinName, MB_OK);
	}
	/*�@�A���C���X�g�[���L�[�폜�@*/
	RegDeleteKey(HKEY_LOCAL_MACHINE, "SoftWare\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Eram");
	/*�@�C�x���g���O�p�L�[�폜�@*/
	RegDeleteKey(HKEY_LOCAL_MACHINE, "System\\CurrentControlSet\\Services\\EventLog\\System\\Eram");
	/*�@�ċN�����K�v�Ȃ��Ƃ��Z�b�g�@*/
	bReboot = TRUE;
	/*�@���u�[�g�w���@*/
	Reboot(hWnd);
}


/*�@�ȍ~��Windows2000�ȍ~��p�@*/
/*�@Eram2000UnInstall
		�A���C���X�g�[��(Windows2000:�f�o�C�X�}�l�[�W��)
	����
		hWnd		�e�E�B���h�E�n���h��
	�߂�l
		����
*/

BOOL WINAPI Eram2000UnInstall(HWND hWnd)
{
	/*�@���[�J���ϐ��@*/
	static GUID EramClass = { 0xFB6B01E0, 0x3191, 0x11D4, 0x99, 0x10, 0x00, 0x00, 0x4C, 0x67, 0x20, 0x63 };
	LPCSTR lpszEramClass;
	HDEVINFO hDevInfoSet;
	SP_DEVINFO_DATA DevInfoData;
	CHAR szBuf[128], szSubKey[MAX_PATH], szInfPath[MAX_PATH], szText[128];
	HKEY hKey;
	UINT loopi;
	BOOL bStat;
	/*�@SETUPAPI.DLL���[�h�@*/
	sSetupApi.hSetupApi = (HMODULE)LoadLibrary("setupapi");
	if (sSetupApi.hSetupApi == NULL)		/*�@SETUPAPI.DLL���[�h���s�@*/
	{
		wsprintf(szBuf, GetResStr(IDS_ERR_LOAD_SETUPAPI, szText, sizeof(szText)), GetLastError());
		MessageBox(hWnd, szBuf, szWinName, MB_OK);
		return FALSE;
	}
	sSetupApi.lpfnSetupDiGetClassDevs = (LPFNSETUPDIGETCLASSDEVSA)GetProcAddress(sSetupApi.hSetupApi, "SetupDiGetClassDevsA");
	sSetupApi.lpfnSetupDiEnumDeviceInfo = (LPFNSETUPDIENUMDEVICEINFO)GetProcAddress(sSetupApi.hSetupApi, "SetupDiEnumDeviceInfo");
	sSetupApi.lpfnSetupDiRemoveDevice = (LPFNSETUPDIREMOVEDEVICE)GetProcAddress(sSetupApi.hSetupApi, "SetupDiRemoveDevice");
	sSetupApi.lpfnSetupDiDestroyDeviceInfoList = (LPFNSETUPDIDESTROYDEVICEINFOLIST)GetProcAddress(sSetupApi.hSetupApi, "SetupDiDestroyDeviceInfoList");
	sSetupApi.lpfnSetupDiOpenDevRegKey = (LPFNSETUPDIOPENDEVREGKEY)GetProcAddress(sSetupApi.hSetupApi, "SetupDiOpenDevRegKey");
	if ((sSetupApi.lpfnSetupDiGetClassDevs == NULL)||
		(sSetupApi.lpfnSetupDiEnumDeviceInfo == NULL)||
		(sSetupApi.lpfnSetupDiRemoveDevice == NULL)||
		(sSetupApi.lpfnSetupDiDestroyDeviceInfoList == NULL)||
		(sSetupApi.lpfnSetupDiOpenDevRegKey == NULL))
	{
		wsprintf(szBuf, GetResStr(IDS_ERR_GETPROC_SETUPAPI, szText, sizeof(szText)), GetLastError());
		MessageBox(hWnd, szBuf, szWinName, MB_OK);
		return FALSE;
	}
	/*�@ERAM�N���X�̃f�o�C�X�񋓂������@*/
	hDevInfoSet = (*(sSetupApi.lpfnSetupDiGetClassDevs))(&EramClass, NULL, hWnd, 0);
	if (hDevInfoSet == INVALID_HANDLE_VALUE)		/*�@ERAM�N���X�s�݁@*/
	{
		return TRUE;
	}
	bStat = FALSE;
	__try
	{
		/*�@ANSI�\���̂�ݒ�@*/
		DevInfoData.cbSize = sizeof(DevInfoData);
		for (loopi=0; loopi<MAXINSTANCE; loopi++)
		{
			/*�@ERAM�N���X�̃f�o�C�X��񋓁@*/
			if ((*(sSetupApi.lpfnSetupDiEnumDeviceInfo))(hDevInfoSet, loopi, &DevInfoData) == FALSE)
			{
				if (GetLastError() == ERROR_NO_MORE_ITEMS)	/*�@�񋓏I���@*/
				{
					break;
				}
				wsprintf(szBuf, GetResStr(IDS_ERR_DRIVER_ENUM, szText, sizeof(szText)), GetLastError());
				MessageBox(hWnd, szBuf, szWinName, MB_OK);
				__leave;
			}
			/*�@�Ή�����INF�t�@�C�����擾�@*/
			if (GetInfName(hDevInfoSet, &DevInfoData, szInfPath, sizeof(szInfPath)) == FALSE)
			{
				szInfPath[0] = '\0';
			}
			/*�@�h���C�o�G���g��1�폜�@*/
			if ((*(sSetupApi.lpfnSetupDiRemoveDevice))(hDevInfoSet, &DevInfoData) == FALSE)
			{
				wsprintf(szBuf, GetResStr(IDS_ERR_DRIVER_REMOVE, szText, sizeof(szText)), GetLastError());
				MessageBox(hWnd, szBuf, szWinName, MB_OK);
				__leave;
			}
			/*�@INF�t�@�C���폜�@*/
			if (szInfPath[0] != '\0')
			{
				DeleteInfFiles(szInfPath);
			}
		}
		bStat = TRUE;
	}
	__finally
	{
		(*(sSetupApi.lpfnSetupDiDestroyDeviceInfoList))(hDevInfoSet);
	}
	if (bStat != FALSE)		/*�@�폜�����@*/
	{
		/*�@ERAM�N���X������쐬�@*/
		lpszEramClass = GetEramClass(&EramClass);
		if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpszEramClass, 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
		{
			/*�@�S�T�u�L�[�폜�@*/
			for (;;)
			{
				if (RegEnumKey(hKey, 0, szSubKey, sizeof(szSubKey)) != ERROR_SUCCESS)
				{
					break;
				}
				RegDeleteKey(hKey, szSubKey);
			}
			RegCloseKey(hKey);
		}
		/*�@ERAM�N���X�폜�@*/
		RegDeleteKey(HKEY_LOCAL_MACHINE, lpszEramClass);
	}
	/*�@�ύX�ʒm�@*/
	SendMessage(HWND_BROADCAST, WM_DEVICECHANGE, DBT_DEVNODES_CHANGED, 0);
	return bStat;
}


/*�@GetInfName
		�A���C���X�g�[��:INF�t�@�C�����擾
	����
		hWnd		�e�E�B���h�E�n���h��
	�߂�l
		����
*/

BOOL WINAPI GetInfName(HDEVINFO hDevInfoSet, PSP_DEVINFO_DATA pDevInfoData, LPSTR lpszInfPath, DWORD dwSize)
{
	/*�@���[�J���ϐ��@*/
	HKEY hKey;
	BOOL bStat;
	LONG lRet;
	DWORD dwType;
	bStat = FALSE;
	/*�@���W�X�g���L�[�I�[�v���@*/
	hKey = (*(sSetupApi.lpfnSetupDiOpenDevRegKey))(hDevInfoSet, pDevInfoData, DICS_FLAG_GLOBAL, 0, DIREG_DRV, KEY_READ);
	if (hKey != INVALID_HANDLE_VALUE)
	{
		/*�@INF�t�@�C�����擾�@*/
		lRet = RegQueryValueEx(hKey, "InfPath", NULL, &dwType, (LPBYTE)lpszInfPath, &dwSize);
        if ((lRet == ERROR_SUCCESS)&&(dwType == REG_SZ))
		{
			bStat = TRUE;
		}
		RegCloseKey(hKey);
	}
	if (bStat == FALSE)
	{
		*lpszInfPath = '\0';
	}
	return bStat;
}


/*�@DeleteInfFiles
		�A���C���X�g�[��:INF�t�@�C���폜
	����
		lpszInf		INF�t�@�C����
	�߂�l
		����
*/

BOOL WINAPI DeleteInfFiles(LPCSTR lpszInf)
{
	/*�@���[�J���ϐ��@*/
	CHAR szWinDir[MAX_PATH], szBase[_MAX_FNAME], szExt[_MAX_EXT], szPath[MAX_PATH];
	INT nLen;
	/*�@Windows�f�B���N�g���擾�@*/
	if (GetWindowsDirectory(szWinDir, sizeof(szWinDir)) == 0)
	{
		return FALSE;
	}
	/*�@�g���q�𕪉��@*/
	_splitpath(lpszInf, NULL, NULL, szBase, szExt);
	if (lstrcmpi(szExt, ".INF") != 0)
	{
		return FALSE;
	}
	nLen = wsprintf(szPath, "%s\\INF\\%s", szWinDir, szBase);
	if (nLen == 0)
	{
		return FALSE;
	}
	/*�@INF�t�@�C���폜�@*/
	lstrcpy(&(szPath[nLen]), szExt);
	if ((DeleteFile(szPath) == FALSE)||
		(MoveFileEx(szPath, NULL, MOVEFILE_DELAY_UNTIL_REBOOT) == FALSE))
	{
		return FALSE;
	}
	/*�@PNF�t�@�C���폜�@*/
	szPath[nLen+1] = 'P';
	if ((DeleteFile(szPath) == FALSE)||
		(MoveFileEx(szPath, NULL, MOVEFILE_DELAY_UNTIL_REBOOT) == FALSE))
	{
		return FALSE;
	}
	return TRUE;
}


/*�@GetEramClass
		�A���C���X�g�[��:ERAM�N���X�����񍇐�
	����
		pGuid	�N���XGUID
	�߂�l
		���W�X�g���L�[������
*/

LPCSTR WINAPI GetEramClass(GUID* pGuid)
{
	/*�@���[�J���ϐ��@*/
	static CHAR szEramClass[MAX_PATH];
	wsprintf(szEramClass,
			"SYSTEM\\CurrentControlSet\\Control\\Class\\{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
			pGuid->Data1,
			pGuid->Data2,
			pGuid->Data3,
			pGuid->Data4[0], pGuid->Data4[1],
			pGuid->Data4[2], pGuid->Data4[3], pGuid->Data4[4], pGuid->Data4[5], pGuid->Data4[6], pGuid->Data4[7]);
	return (LPCSTR)szEramClass;
}


/*�@�ȍ~��WindowsNT4.0�ȍ~��p�@*/
/*�@StartupFastfat
		FASTFAT�h���C�o �X�^�[�g�A�b�v�ύX�@RUNDLL32 ERAMNT.CPL,StartupFastfat 0�`4
	����
		hWnd		�e�E�B���h�E�n���h��
		hInstance	�C���X�^���X�n���h��
		lpszCmdLine	����
		nCmdShow	�\�����
	�߂�l
		�Ȃ�
*/

VOID EXPORT CALLBACK StartupFastfat(HWND hWnd, HINSTANCE hInstance, LPSTR lpszCmdLine, INT nCmdShow)
{
	/*�@���[�J���ϐ��@*/
	static WORD wTypes[] = {
		IDS_START_TYPE_0, IDS_START_TYPE_1, IDS_START_TYPE_2, IDS_START_TYPE_3, IDS_START_TYPE_4
	};
	SC_HANDLE hScm, hFat;
	CHAR szMsg[256], szText[128], szType[32];
	DWORD dwError, dwStartType, dwNeed;
	BOOL bCmdOk;
	LPQUERY_SERVICE_CONFIG lpConf;
	bCmdOk = FALSE;
	if (lpszCmdLine != NULL)
	{
		switch (*lpszCmdLine)
		{
		case '0':		/*�@SERVICE_BOOT_START�@*/
		case '1':		/*�@SERVICE_SYSTEM_START�@*/
		case '2':		/*�@SERVICE_AUTO_START�@*/
		case '3':		/*�@SERVICE_DEMAND_START�@*/
		case '4':		/*�@SERVICE_DISABLED�@*/
			if (lpszCmdLine[1] == '\0')
			{
				bCmdOk = TRUE;
			}
			break;
		}
	}
	if (bCmdOk == FALSE)
	{
		MessageBox(hWnd, GetResStr(IDS_INFO_FASTFAT_USAGE, szText, sizeof(szText)), szWinName, MB_OK);
		return;
	}
	dwStartType = *lpszCmdLine - '0';
	/*�@SCM�ڑ��@*/
	hScm = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);
	if (hScm == NULL)
	{
		dwError = GetLastError();
		if (dwError == ERROR_ACCESS_DENIED)
		{
			MessageBox(hWnd, GetResStr(IDS_ERR_NEED_CTRL_PRIV, szText, sizeof(szText)), szWinName, MB_OK);
			return;
		}
		wsprintf(szMsg, GetResStr(IDS_ERR_OPEN_SCM, szText, sizeof(szText)), dwError);
		MessageBox(hWnd, szMsg, szWinName, MB_OK);
		return;
	}
	hFat = NULL;
	__try
	{
		/*�@FASTFAT�h���C�o�I�[�v���@*/
		hFat = OpenService(hScm, "Fastfat", SERVICE_QUERY_CONFIG | SERVICE_CHANGE_CONFIG);
		if (hFat == NULL)
		{
			wsprintf(szMsg, GetResStr(IDS_ERR_OPEN_FASTFAT, szText, sizeof(szText)), GetLastError());
			MessageBox(hWnd, szMsg, szWinName, MB_OK);
			__leave;
		}
		/*�@�X�^�[�g�A�b�v�^�C�v�m�F�@*/
		QueryServiceConfig(hFat, NULL, 0, &dwNeed);
		if (dwNeed != 0)
		{
			lpConf = (LPQUERY_SERVICE_CONFIG)_alloca(dwNeed);
			if ((lpConf != NULL)&&
				(QueryServiceConfig(hFat, lpConf, dwNeed, &dwNeed) != FALSE)&&
				(lpConf->dwStartType == dwStartType))
			{
				wsprintf(szMsg, GetResStr(IDS_INFO_FASTFAT_ALREADY, szText, sizeof(szText)), GetResStr(wTypes[dwStartType], szType, sizeof(szType)));
				MessageBox(hWnd, szMsg, szWinName, MB_OK);
				__leave;
			}
		}
		/*�@�X�^�[�g�A�b�v�^�C�v�ύX�@*/
		if (ChangeServiceConfig(hFat, SERVICE_NO_CHANGE, dwStartType, SERVICE_NO_CHANGE, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == FALSE)
		{
			wsprintf(szMsg, GetResStr(IDS_ERR_FASTFAT_MODIFY, szText, sizeof(szText)), GetLastError());
			MessageBox(hWnd, szMsg, szWinName, MB_OK);
			__leave;
		}
		wsprintf(szMsg, GetResStr(IDS_INFO_FASTFAT_MODIFY, szText, sizeof(szText)), GetResStr(wTypes[dwStartType], szType, sizeof(szType)));
		MessageBox(hWnd, szMsg, szWinName, MB_OK);
	}
	__finally
	{
		if (hFat != NULL)
		{
			CloseServiceHandle(hFat);
		}
		CloseServiceHandle(hScm);
	}
}


/*�@�ȍ~�͋��ʁ@*/
/*�@GetResStr
		���\�[�X������擾
	����
		wId			�����񃊃\�[�XID
		lpszBuf		�o�b�t�@�̃|�C���^
		nSize		�o�b�t�@�̑傫��
	�߂�l
		�o�b�t�@�̃|�C���^
*/

LPSTR WINAPI GetResStr(WORD wId, LPSTR lpszBuf, INT nSize)
{
	/*�@���[�J���ϐ��@*/
	DWORD dwError;
	dwError = GetLastError();
	if (LoadString(hgInstance, wId, lpszBuf, nSize) == 0)
	{
		*lpszBuf = '\0';
	}
	SetLastError(dwError);
	return lpszBuf;
}


/*�@DllMain
		DLL�G���g��
	����
		hInstance	����DLL�̃C���X�^���X�n���h��
		fdwReason	�Ăяo�����R
		lpvReserved	�\��
	�߂�l
		����
*/

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		hgInstance = hInstance;
		DisableThreadLibraryCalls(hInstance);
		break;
	}
	return TRUE;
}

