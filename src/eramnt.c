/*�@ERAMNT.C�@�@RAM�f�B�X�NERAM for WindowsNT/2000/XP
�@�@�@Copyright (c) 1999-2004 by *Error15
*/

/*�@�X�V����
	v1.00
		�V�K�쐬
	v1.01
		over32MB�Ή�(64MB�܂�)
		Win2000��3�Ή�
	v1.10
		Win2000����m�F
	v1.11
		�������m�ێ��s���ARAM�ʂ̖ڈ����o���悤�ɂ���
		FAT12��FAT16�̋��E������̃N���X�^���v�Z�Ƀ~�X���������̂��C��
	v2.00
		MAXMEM=nn�ȍ~�̃�������64KB�P�ʂŐ؂�ւ����Ĉ���
	v2.01
		�A���P�[�V�������j�b�g32�𑝂₵��1GB�m�ۉ\�c
	v2.02
		MAXMEM=nn�ȍ~�̃������̊J�n�A�h���X���w��\�ɂ���
		�h���C�u�^�C�v�����[�J���f�B�X�N�����ɂ��ăX���b�v�\�ɂ��ł���
		�C�x���g���O���b�Z�[�W�ǉ�
	v2.10
		FAT32�Ή�
		FAT16 over32MB�Ńp�[�e�[�V�����𐳂����Ԃ��悤�ɕύX
		FAT16�ł��A���P�[�V�������j�b�g64�𑝂₵��2GB�m�ۉ\�c
		�{�����[���V���A���ԍ��Ɍ��ݓ��t��ݒ肷��悤�ύX
	v2.11
		WinXP�Ή�
	v2.12
		�X�^���o�C�Ή�
			IoReportResourceUsage�ĂԂƃX�^���o�C�ł��Ȃ��Ȃ�(��ŊJ�����Ă�)
			IoReportResourceForDetection�ł́Aover16MB�ȓ����������v�����ʂ�Ȃ�
			IoReportResourceUsage�Ă΂Ȃ��Ă�HalTranslateBusAddress�ł���
			HalTranslateBusAddress���Ȃ��Ă������������͓���A�h���X������
			�X�^���o�C(�d��ON�̂܂�)�cRAM��OS�Ǘ��O�ł�ok
			�x�~���(�d��OFF)�cRAM��OS�Ǘ��O�ł͕s��(OS�Ǘ��Ȃ�ok)
	v2.20
		�O���������ʂ̌v�Z�������t���ɂȂ��Ă��̂��C��(���Q����)
		�O���������̌��o�̂������4GB���b�v���Ȃ��悤�v�Z�ǉ�
		�I�v�V����������r����������UNICODE�Ή����ĂȂ������̂��C��
		FAT16�ő�N���X�^��65535��65525�ɏC��
		FAT32�ő�N���X�^�𖢌�����268435455(=0xFFFFFFF)�ɏC�� (Win2000=4177918)
		�ő�e�ʂ��ő�N���X�^x�A���P�[�V�������j�b�g���ɐ���(�����ɂ͗]�T���邪����)
		�ő�e�ʂ�4GB�ɐ���
			NT�n�ł�FAT16�ő�e�ʂ�4GB�����Achkdsk���̕\������
		�N���X�^�����Ő؂�グ���Ă��̂���߁A�؂�̂ĂɕύX
		FAT32�N���X�^��65527�`�������̂�65526�`�ɕύX
		�������̏��Ȃ��@��ł��e�X�g�\�Ȃ悤�ɉ���
			�O���������g�p�ݒ莞�A������m�ۂł���悤�ɂ���
			(�Â��n�[�h�ł̓A�h���X�o�X��32bit�t���f�R�[�h����Ă��Ȃ����Ƃ�����)
		�������}�b�v�g�t�@�C�����g���ăe�X�g�\�Ȃ悤�ɉ���(�t�@�C���V�X�e���h���C�o�̃��[�h�O��)
			�t�@�C��I/O�ł�ZwXXX�ł͋����ɂ��܂��Ή��ł��Ȃ��悤�Ȃ̂Ń}�b�v�g�t�@�C���g�p
			�o�̓t�@�C���ύX�Ή�
		�N�����̗̈�N���A�ŊǗ��̈�݂̂�Ώۂɂ���悤�ύX
		�I�v�V����32bit��
		Windows2000�ȍ~�Ŏ�����FAT32��L��������悤�ύX
		�x���t�@�C�����𖳌���(�傫���`�F�b�N�̂ݎ���)
		�Z�N�^/�g���b�N��񂪌���Ă����̂��C��
		Windows Server 2003�Ή�
		IOCTL_DISK_GET_LENGTH_INFO�����ǉ�
			XP�ȍ~�ł̓f�B�X�N�e�ʂ��v�Z���Ă���Ȃ��Ă��̑Ή��K�{�̖͗l
		IOCTL_DISK_SET_PARTITION_INFO�����ǉ�
			NTFS�ւ�convert�Ƃ�format���ł���悤�Ȃ̂ňꉞ
		FAT12�ő�N���X�^��4087��4086�ɏC��
		�{�����[�����x���ύX�Ή�
			*?/|.,;:+=[]()&^<>" �ƃR���g���[���R�[�h�͎w��s��
		�C�x���g���O�o�͂ŁAUNICODE��ANSI[��UNICODE]�ϊ����Ă��̂�ANSI��UNICODE�ɉ��P
		�X���b�v�֌W�������f�o�C�X�ݒ�\�ɂ���
		�����������I�����̕␳�@�\�ǉ�
		FAT12/16:���[�g�f�B���N�g���Z�N�^���S�Z�N�^������Ƃ��듮�삵�Ă��̂��C��
		TEMP�f�B���N�g���쐬�@�\�ǉ�
		����(��)���������@�\
			NTFS�t�H�[�}�b�g
				���낢��ʓ|�Ȃ̂�format��convert�œ����Ă��炤
				�N������format����ꍇ�A�ȉ��̐ݒ�ŉ���ł��邩������Ȃ�
					Run�������
						cmd.exe /c convert drv: /fs:ntfs < %systemroot%\system32\eramconv.txt
					system32\eramconv.txt�������
						volume-label
						y
						n
					�t�H���_���J����Ă�convert�ł��Ȃ����Ƃ�����
					HDD(=�X���b�v�g�p�\)�ɂ����format���g�p�\
			�{�����[���}�l�[�W���A�g
				PnP�h���C�o�łȂ��ƍ�����ۂ��̂ŕ��u
				�}�E���g�|�C���g(NTFS5)�͎g���Ȃ�
				�n�[�h�����N���g���Ȃ� symlink rktools linkd
			XP:�y�[�W�t�@�C����u���Ȃ�
				�}�E���g�}�l�[�W���ɔF������ĂȂ���Ԃł͑Ώ��s�\�̖͗l
				Start��0�ɁAPrimary disk�ɂ��Ă��ʖ�
				XP�ȍ~�y�[�W�t�@�C�������ɂł���̂ŁA����ŉ���肤
			/BURNMEMORY=n�Ή�
				http://msdn.microsoft.com/library/en-us/ddtools/hh/ddtools/bootini_9omr.asp
				�h���C�o���[�h���Ƀ����������ʂ��擾���镁�ՓI�Ȏ�i���s��
				HKLM\HARDWARE\RESOURCEMAP\System Resources\Physical Memory\�͂܂��ł��ĂȂ�
	v2.21�b���
		ACPI:ACPI Reclaim/NVS���������O
		NT�f�o�C�X�������W�X�g������擾�ł���悤�ɂ���(���������ERAM���g���ꍇ����)
			HKLM\System\CurrentControlSet\Services\ERAM �̂������ ERAM2 �Ƃ��ɂ���
			�l DevName (REG_SZ)�� \Device\ERAM2 �Ƃ�����ă��u�[�g
			Win2000�ȍ~�ł̓f�o�C�X�}�l�[�W���ɕ\������Ȃ���NT�p��INF�œ����
	v2.22�b���
		ACPI:ACPI Reclaim/NVS���������O�ŃG���[�����ǉ�
		over4GB:/MAXMEM=n��/NOLOWMEM���ݎ���MAXMEM��over4GB�Ɍ������Ƃ̑΍�(�V�� �X���ʂ���w�E����)
			�v�[���̕����A�h���X��over4GB�̂Ƃ��A/PAE�w��Ƃ݂Ȃ�
			/PAE�w��Ƃ݂Ȃ����Ƃ��A/NOLOWMEM�w����T��
			/NOLOWMEM�w�莞��/MAXMEM=16�Ɠ����ƌ��Ȃ�
	v2.23�b���
		over4GB:/MAXMEM=n��/NOLOWMEM���ݎ���MAXMEM��over4GB�Ɍ������Ƃ̑΍�(�V�� �X���ʂ���w�E����)
			/PAE:v2.22��16�ɂ������A16�̓`�F�b�N�ł͂����Ă��̂�17�ɏC��
		��:over4GB:/PAE�����Ă�/NOLOWMEM���������Ƃ̑΍�(�V�� �X���ʂ���w�E)
			/PAE�w�薳���Ă�/NOLOWMEM�w���T����?
			PagedPool�Ɏg���Ă���̂Ō��E�l�����o�ł��Ȃ��悤�����c
		��:over4GB:LME��Ԃł�RAM���m��?
		��:SMBIOS:�������ő�ʎ擾
		��:SUM�`�F�b�N
*/


#pragma warning(disable : 4100 4115 4201 4214 4514 )
#include <ntddk.h>
#include <ntdddisk.h>
#include <devioctl.h>
#include <ntddstor.h>
#include <ntiologc.h>
#include "eramnt.h"
#include "eramntum.h"
#pragma pack(1)



/*�@EramCreateClose
		�I�[�v��/�N���[�Y�v���G���g��
	����
		pDevObj	���u�I�u�W�F�N�g�ւ̃|�C���^
		pIrp	IRP�p�P�b�g�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS EramCreateClose(
	IN PDEVICE_OBJECT	pDevObj,
	IN PIRP				pIrp
 )
{
	KdPrint(("EramCreateClose start\n"));
	/*�@�������Z�b�g�@*/
	pIrp->IoStatus.Status = STATUS_SUCCESS;
	pIrp->IoStatus.Information = 0;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	KdPrint(("EramCreateClose end\n"));
	return STATUS_SUCCESS;
}


/*�@EramDeviceControl
		�f�o�C�X�R���g���[���v���G���g��
	����
		pDevObj	���u�I�u�W�F�N�g�ւ̃|�C���^
		pIrp	IRP�p�P�b�g�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS EramDeviceControl(
	IN PDEVICE_OBJECT	pDevObj,
	IN PIRP				pIrp
 )
{
	/*�@���[�J���ϐ��@*/
	PERAM_EXTENSION		pEramExt;
	PIO_STACK_LOCATION	pIrpSp;
	NTSTATUS			ntStat;
	//KdPrint(("EramDeviceControl start\n"));
	/*�@�\���̐擪�|�C���^�擾�@*/
	pEramExt = pDevObj->DeviceExtension;
	/*�@�X�^�b�N�ւ̃|�C���^�擾�@*/
	pIrpSp = IoGetCurrentIrpStackLocation(pIrp);
	/*�@���s���Z�b�g�@*/
	pIrp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;
	pIrp->IoStatus.Information = 0;
	switch (pIrpSp->Parameters.DeviceIoControl.IoControlCode)	/*�@�v���^�C�v�ɂ�蕪��@*/
	{
	case IOCTL_DISK_GET_MEDIA_TYPES:		/*�@���f�B�A�^�C�v�擾(�z��)�@*/
	case IOCTL_DISK_GET_DRIVE_GEOMETRY:		/*�@���f�B�A�^�C�v�擾(1)�@*/
		/*�@�W�I���g���擾�����@*/
		EramDeviceControlGeometry(pEramExt, pIrp, pIrpSp->Parameters.DeviceIoControl.OutputBufferLength);
		break;
	case IOCTL_DISK_GET_PARTITION_INFO:		/*�@�p�[�e�[�V�������擾�@*/
		/*�@�p�[�e�[�V�������擾�����@*/
		EramDeviceControlGetPartInfo(pEramExt, pIrp, pIrpSp->Parameters.DeviceIoControl.OutputBufferLength);
		break;
	case IOCTL_DISK_SET_PARTITION_INFO:		/*�@�p�[�e�[�V�������擾�@*/
		/*�@�p�[�e�[�V�������ݒ菈���@*/
		EramDeviceControlSetPartInfo(pEramExt, pIrp, pIrpSp->Parameters.DeviceIoControl.InputBufferLength);
		break;
	case IOCTL_DISK_VERIFY:					/*�@�x���t�@�C�@*/
		/*�@�x���t�@�C�����@*/
		EramDeviceControlVerify(pEramExt, pIrp, pIrpSp->Parameters.DeviceIoControl.InputBufferLength);
		break;
	case IOCTL_DISK_CHECK_VERIFY:			/*�@�f�B�X�N����(Win2000��3�ȍ~)�@*/
		/*�@�x���t�@�C�����@*/
		EramDeviceControlDiskCheckVerify(pEramExt, pIrp, pIrpSp->Parameters.DeviceIoControl.OutputBufferLength);
		break;
	case IOCTL_DISK_GET_LENGTH_INFO:		/*�@�f�B�X�N�T�C�Y�擾(Win2000�` [WinXP�ȍ~format/convert���K�{])�@*/
		/*�@�f�B�X�N�T�C�Y�擾�����@*/
		EramDeviceControlGetLengthInfo(pEramExt, pIrp, pIrpSp->Parameters.DeviceIoControl.OutputBufferLength);
		break;
	default:								/*�@���̑��@*/
		/*�@�����@*/
		KdPrint(("IOCTL 0x%x\n", (UINT)(pIrpSp->Parameters.DeviceIoControl.IoControlCode)));
		break;
	}
	/*�@�X�e�[�^�X���Z�b�g�@*/
	ntStat = pIrp->IoStatus.Status;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	//KdPrint(("EramDeviceControl end\n"));
	return ntStat;
}


/*�@EramDeviceControlGeometry
		�W�I���g���擾����
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		uLen		�o�b�t�@�T�C�Y
	�߂�l
		�Ȃ�
*/

VOID EramDeviceControlGeometry(
	PERAM_EXTENSION	pEramExt,
	IN PIRP			pIrp,
	IN ULONG		uLen
 )
{
	/*�@���[�J���ϐ��@*/
	PDISK_GEOMETRY pGeom;
	if (uLen < sizeof(*pGeom))		/*�@�T�C�Y�s���@*/
	{
		pIrp->IoStatus.Status = STATUS_INVALID_PARAMETER;
		KdPrint(("EramDeviceControlGeometry:size too small\n"));
		return;
	}
	/*�@�f�B�X�N�W�I���g���ݒ�@*/
	pGeom = (PDISK_GEOMETRY)(pIrp->AssociatedIrp.SystemBuffer);
	pGeom->MediaType = FixedMedia;		/*�@���f�B�A�^�C�v:�Œ�f�B�X�N�@*/
	pGeom->Cylinders.QuadPart = (ULONGLONG)(pEramExt->uAllSector);
	pGeom->TracksPerCylinder = 1;
	pGeom->SectorsPerTrack = 1;			/*�@1�o���N������̃Z�N�^���@*/
	pGeom->BytesPerSector = SECTOR;
	pIrp->IoStatus.Status = STATUS_SUCCESS;
	pIrp->IoStatus.Information = sizeof(*pGeom);
}


/*�@EramDeviceControlGetPartInfo
		�p�[�e�[�V�������擾����
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		uLen		�o�b�t�@�T�C�Y
	�߂�l
		�Ȃ�
*/

VOID EramDeviceControlGetPartInfo(
	PERAM_EXTENSION	pEramExt,
	IN PIRP			pIrp,
	IN ULONG		uLen
 )
{
	/*�@���[�J���ϐ��@*/
	PPARTITION_INFORMATION pPart;
	if (uLen < sizeof(*pPart))		/*�@�T�C�Y�s���@*/
	{
		pIrp->IoStatus.Status = STATUS_INVALID_PARAMETER;
		KdPrint(("EramDeviceControlGetPartInfo:size too small\n"));
		return;
	}
	/*�@�p�[�e�[�V�������ݒ�@*/
	pPart = (PPARTITION_INFORMATION)(pIrp->AssociatedIrp.SystemBuffer);
	pPart->PartitionType = pEramExt->FAT_size;
	pPart->BootIndicator = FALSE;			/*�@�u�[�g�s�@*/
	pPart->RecognizedPartition = TRUE;		/*�@�p�[�e�[�V�����F���@*/
	pPart->RewritePartition = FALSE;		/*�@�ď������ݕs�p�[�e�[�V�����@*/
	pPart->StartingOffset.QuadPart = (ULONGLONG)(0);	/*�@�p�[�e�[�V�����J�n�ʒu�@*/
	pPart->PartitionLength.QuadPart = UInt32x32To64(pEramExt->uAllSector, SECTOR);	/*�@�����@*/
	pPart->HiddenSectors =  pEramExt->bsHiddenSecs;	/*�@�B���Z�N�^���@*/
	pPart->PartitionNumber = 1;				/*�@�p�[�e�[�V�������@*/
	pIrp->IoStatus.Status = STATUS_SUCCESS;
	pIrp->IoStatus.Information = sizeof(PARTITION_INFORMATION);
}


/*�@EramDeviceControlSetPartInfo
		�p�[�e�[�V�������ݒ菈��
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		uLen		�o�b�t�@�T�C�Y
	�߂�l
		�Ȃ�
*/

VOID EramDeviceControlSetPartInfo(
	PERAM_EXTENSION	pEramExt,
	IN PIRP			pIrp,
	IN ULONG		uLen
 )
{
	/*�@���[�J���ϐ��@*/
	PSET_PARTITION_INFORMATION pPart;
	if (uLen < sizeof(*pPart))		/*�@�T�C�Y�s���@*/
	{
		pIrp->IoStatus.Status = STATUS_INVALID_PARAMETER;
		KdPrint(("EramDeviceControlSetPartInfo:size too small\n"));
		return;
	}
	/*�@�p�[�e�[�V�������ݒ�@*/
	pPart = (PSET_PARTITION_INFORMATION)(pIrp->AssociatedIrp.SystemBuffer);
	pEramExt->FAT_size = pPart->PartitionType;
	pIrp->IoStatus.Status = STATUS_SUCCESS;
}


/*�@EramDeviceControlVerify
		�x���t�@�C����
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		uLen		�o�b�t�@�T�C�Y
	�߂�l
		�Ȃ�
*/

VOID EramDeviceControlVerify(
	PERAM_EXTENSION		pEramExt,
	IN PIRP				pIrp,
	IN ULONG			uLen
 )
{
	/*�@���[�J���ϐ��@*/
	PVERIFY_INFORMATION	pVerify;
	//KdPrint(("EramDeviceControlVerify start\n"));
	if (uLen < sizeof(*pVerify))		/*�@�T�C�Y�s���@*/
	{
		pIrp->IoStatus.Status = STATUS_INVALID_PARAMETER;
		KdPrint(("EramDeviceControlVerify:size too small\n"));
		return;
	}
	/*�@�x���t�@�C���ݒ�@*/
	pVerify = pIrp->AssociatedIrp.SystemBuffer;
	//KdPrint(("offset 0x%x%08x, len 0x%x\n", pVerify->StartingOffset.HighPart, pVerify->StartingOffset.LowPart, pVerify->Length));
	if ((((ULONGLONG)(pVerify->StartingOffset.QuadPart) + (ULONGLONG)(pVerify->Length)) > UInt32x32To64(pEramExt->uAllSector, SECTOR))||
		((pVerify->StartingOffset.LowPart & (SECTOR-1)) != 0)||
		((pVerify->Length & (SECTOR-1)) != 0))	/*�@�f�B�X�N�e�ʂ𒴂���or�J�n�ʒu/�������Z�N�^�T�C�Y�̔{���łȂ��@*/
	{
		/*�@�G���[��Ԃ��@*/
		KdPrint(("Invalid I/O parameter\n"));
		pIrp->IoStatus.Status = STATUS_INVALID_PARAMETER;
		return;
	}
	if ((pEramExt->uOptflag.Bits.External != 0)&&	/*�@OS�Ǘ��O�������g�p�@*/
		(pEramExt->uExternalStart != 0)&&			/*�@OS�Ǘ��O�������ݒ�@*/
		((pEramExt->uExternalStart + (ULONGLONG)(pVerify->StartingOffset.QuadPart) + (ULONGLONG)(pVerify->Length)) >= 
pEramExt->uExternalEnd))
	{
		//KdPrint(("Invalid I/O address space\n"));
		pIrp->IoStatus.Status = STATUS_DISK_CORRUPT_ERROR;
		return;
	}
	pIrp->IoStatus.Status = STATUS_SUCCESS;
	//KdPrint(("EramDeviceControlVerify end\n"));
}


/*�@EramDeviceControlDiskCheckVerify
		�f�B�X�N�����m�F����
	����
		pEdskExt	EDSK_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		uLen		�o�b�t�@�T�C�Y
	�߂�l
		�Ȃ�
*/

VOID EramDeviceControlDiskCheckVerify(
	PERAM_EXTENSION	pEramExt,
	IN PIRP			pIrp,
	IN ULONG		uLen
 )
{
	/*�@���[�J���ϐ��@*/
	PULONG puOpt;
	pIrp->IoStatus.Status = STATUS_SUCCESS;
	if (uLen == 0)		/*�@�⑫���s�v�@*/
	{
		return;
	}
	if (uLen < sizeof(*puOpt))		/*�@�T�C�Y�s���@*/
	{
		pIrp->IoStatus.Status = STATUS_INVALID_PARAMETER;
		KdPrint(("EramDeviceControlDiskCheckVerify:size too small\n"));
		return;
	}
	/*�@�⑫���ݒ�@*/
	puOpt = (PULONG)(pIrp->AssociatedIrp.SystemBuffer);
	*puOpt = 0;
	pIrp->IoStatus.Information = sizeof(*puOpt);
}


/*�@EramDeviceControlGetLengthInfo
		�f�B�X�N�T�C�Y�擾����
	����
		pEdskExt	EDSK_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		uLen		�o�b�t�@�T�C�Y
	�߂�l
		�Ȃ�
*/

VOID EramDeviceControlGetLengthInfo(
	PERAM_EXTENSION	pEramExt,
	IN PIRP			pIrp,
	IN ULONG		uLen
 )
{
	/*�@���[�J���ϐ��@*/
	PGET_LENGTH_INFORMATION pInfo;
	if (uLen < sizeof(*pInfo))		/*�@�T�C�Y�s���@*/
	{
		pIrp->IoStatus.Status = STATUS_INVALID_PARAMETER;
		KdPrint(("EramDeviceControlGetLengthInfo:size too small\n"));
		return;
	}
	/*�@�T�C�Y���ݒ�@*/
	pInfo = (PGET_LENGTH_INFORMATION)(pIrp->AssociatedIrp.SystemBuffer);
	pInfo->Length.QuadPart = UInt32x32To64(pEramExt->uAllSector, SECTOR);	/*�@�����@*/
	pIrp->IoStatus.Status = STATUS_SUCCESS;
	pIrp->IoStatus.Information = sizeof(*pInfo);
	KdPrint(("EramDeviceControlGetLengthInfo length 0x%x\n", (pEramExt->uAllSector * SECTOR)));
}


/*�@EramReadWrite
		���[�h/���C�g/�x���t�@�C�v���G���g��
	����
		pDevObj		���u�I�u�W�F�N�g�ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS EramReadWrite(
	IN PDEVICE_OBJECT	pDevObj,
	IN PIRP				pIrp
 )
{
	/*�@���[�J���ϐ��@*/
	PERAM_EXTENSION		pEramExt;
	PIO_STACK_LOCATION	pIrpSp;
	PUCHAR				pTransAddr;
	NTSTATUS			ntStat;
	//KdPrint(("EramReadWrite start\n"));
	/*�@�\���̐擪�|�C���^�擾�@*/
	pEramExt = pDevObj->DeviceExtension;
	/*�@�X�^�b�N�ւ̃|�C���^�擾�@*/
	pIrpSp = IoGetCurrentIrpStackLocation(pIrp);
	if ((((ULONGLONG)(pIrpSp->Parameters.Read.ByteOffset.QuadPart) + (ULONGLONG)(pIrpSp->Parameters.Read.Length)) > UInt32x32To64(pEramExt->uAllSector, SECTOR))||
		((pIrpSp->Parameters.Read.ByteOffset.LowPart & (SECTOR-1)) != 0)||
		((pIrpSp->Parameters.Read.Length & (SECTOR-1)) != 0))	/*�@�f�B�X�N�e�ʂ𒴂���or�J�n�ʒu/�������Z�N�^�T�C�Y�̔{���łȂ��@*/
	{
		KdPrint(("Invalid I/O parameter, offset 0x%x, length 0x%x, OP=0x%x(R=0x%x, W=0x%x), limit=0x%x\n", pIrpSp->Parameters.Read.ByteOffset.LowPart, pIrpSp->Parameters.Read.Length, pIrpSp->MajorFunction, IRP_MJ_READ, IRP_MJ_WRITE, (pEramExt->uAllSector * SECTOR)));
		/*�@�G���[��Ԃ��@*/
		pIrp->IoStatus.Status = STATUS_INVALID_PARAMETER;
		IoCompleteRequest(pIrp, IO_NO_INCREMENT);
		return STATUS_INVALID_PARAMETER;
	}
	/*�@�A�h���X�������@*/
	pTransAddr = NULL;
	if (pIrp->MdlAddress != NULL)		/*�@�A�h���X����@*/
	{
		/*�@�A�h���X�ϊ��@*/
		pTransAddr = MmGetSystemAddressForMdl(pIrp->MdlAddress);
	}
	/*�@�������Z�b�g�@*/
	ntStat = STATUS_SUCCESS;
	/*�@�f�[�^����ݒ�@*/
	pIrp->IoStatus.Information = 0;
	switch (pIrpSp->MajorFunction)	/*�@�t�@���N�V�����ɂ�镪��@*/
	{
	case IRP_MJ_READ:				/*�@���[�h�@*/
		//KdPrint(("Read start\n"));
		/*�@�A�h���X���L���Ȃ��Ƃ��m�F�@*/
		if (pTransAddr == NULL)
		{
			KdPrint(("MmGetSystemAddressForMdl failed\n"));
			ntStat = STATUS_INVALID_PARAMETER;
			break;
		}
		/*�@���[�h����ݒ�@*/
		pIrp->IoStatus.Information = pIrpSp->Parameters.Read.Length;
		/*�@���[�h�@*/
		ntStat = (*(pEramExt->EramRead))(pEramExt, pIrp, pIrpSp, pTransAddr);
		//KdPrint(("Read end\n"));
		break;
	case IRP_MJ_WRITE:				/*�@���C�g�@*/
		//KdPrint(("Write start\n"));
		/*�@�A�h���X���L���Ȃ��Ƃ��m�F�@*/
		if (pTransAddr == NULL)
		{
			KdPrint(("MmGetSystemAddressForMdl failed\n"));
			ntStat = STATUS_INVALID_PARAMETER;
			break;
		}
		/*�@���[�h����ݒ�@*/
		pIrp->IoStatus.Information = pIrpSp->Parameters.Write.Length;
		/*�@���C�g�@*/
		ntStat = (*(pEramExt->EramWrite))(pEramExt, pIrp, pIrpSp, pTransAddr);
		//KdPrint(("Write end\n"));
		break;
	default:
		KdPrint(("RW default\n"));
		pIrp->IoStatus.Information = 0;
		break;
	}
	if (ntStat != STATUS_PENDING)		/*�@�ۗ��ȊO�@*/
	{
		/*�@�X�e�[�^�X���Z�b�g�@*/
		pIrp->IoStatus.Status = ntStat;
		/*�@I/O�����@*/
		IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	}
	//KdPrint(("EramReadWrite end\n"));
	return ntStat;
}


/*�@EramUnloadDriver
		�h���C�o��~���̃G���g���|�C���g
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID EramUnloadDriver(
	IN PDRIVER_OBJECT	pDrvObj
 )
{
	/*�@���[�J���ϐ��@*/
	PDEVICE_OBJECT		pDevObj;
	PERAM_EXTENSION		pEramExt;
	KdPrint(("EramUnloadDriver start\n"));
	pDevObj = pDrvObj->DeviceObject;
	pEramExt = (pDevObj != NULL) ? pDevObj->DeviceExtension : NULL;
	/*�@�f�o�C�X�폜�@*/
	EramUnloadDevice(pDrvObj, pDevObj, pEramExt);
	KdPrint(("EramUnloadDriver end\n"));
}


/*�@EramUnloadDevice
		�f�o�C�X�폜
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pDevObj		���u�I�u�W�F�N�g�ւ̃|�C���^
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID EramUnloadDevice(
	IN PDRIVER_OBJECT	pDrvObj,
	IN PDEVICE_OBJECT	pDevObj,
	IN PERAM_EXTENSION	pEramExt
 )
{
	/*�@���[�J���ϐ��@*/
	LARGE_INTEGER llTime;
	KdPrint(("EramUnloadDevice start\n"));
	if (pEramExt != NULL)			/*�@�f�o�C�X�쐬�ς݁@*/
	{
		KdPrint(("Device exist\n"));
		/*�@�X���b�h�I����ʒm�@*/
		pEramExt->bThreadStop = TRUE;
		if (pEramExt->pThreadObject != NULL)		/*�@�X���b�h���݁@*/
		{
			/*�@�Z�}�t�H1���炷�@*/
			KeReleaseSemaphore(&(pEramExt->IrpSem), 0, 1, TRUE);
			/*�@�X���b�h�I���҂�30�b�@*/
			llTime.QuadPart = (LONGLONG)(-30 * 10000000);
			/*�@�X���b�h�I���҂��@*/
			KeWaitForSingleObject(&(pEramExt->pThreadObject), Executive, KernelMode, FALSE, &llTime);
			/*�@�X���b�h�̎Q�ƃJ�E���g�����炷�@*/
			ObDereferenceObject(&(pEramExt->pThreadObject));
			pEramExt->pThreadObject = NULL;
		}
		/*�@�O���t�@�C���N���[�Y�@*/
		if (pEramExt->hSection != NULL)
		{
			KdPrint(("File section close\n"));
			ExtFileUnmap(pEramExt);
			ZwClose(pEramExt->hSection);
			pEramExt->hSection = NULL;
		}
		if (pEramExt->hFile != NULL)
		{
			ZwClose(pEramExt->hFile);
			pEramExt->hFile = NULL;
		}
		/*�@�������}�b�v����@*/
		ResourceRelease(pDrvObj, pEramExt);
		if (pEramExt->Win32Name.Buffer != NULL)		/*�@Win32���쐬�ρ@*/
		{
			/*�@Win32�����N����@*/
			IoDeleteSymbolicLink(&(pEramExt->Win32Name));
			/*�@Win32���̈����@*/
			ExFreePool(pEramExt->Win32Name.Buffer);
			pEramExt->Win32Name.Buffer = NULL;
		}
	}
	if (pDevObj != NULL)		/*�@�f�o�C�X���݁@*/
	{
		/*�@�f�o�C�X�폜�@*/
		IoDeleteDevice(pDevObj);
	}
	KdPrint(("EramUnloadDevice end\n"));
}


/*�@ResourceRelease
		�������}�b�v�폜
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID ResourceRelease(
	IN PDRIVER_OBJECT	pDrvObj,
	IN PERAM_EXTENSION	pEramExt
 )
{
	KdPrint(("ResourceRelease start\n"));
	if (pEramExt->uOptflag.Bits.External != 0)	/*�@OS�Ǘ��O�������g�p�@*/
	{
		/*�@��������@*/
		ReleaseMemResource(pDrvObj, pEramExt);
	}
	else if (pEramExt->pPageBase != NULL)		/*�@�������m�ے��@*/
	{
		/*�@����������@*/
		ExFreePool(pEramExt->pPageBase);
		pEramExt->pPageBase = NULL;
	}
	KdPrint(("ResourceRelease end\n"));
}


/*�@ReleaseMemResource
		OS�Ǘ��O�������}�b�v�폜
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID ReleaseMemResource(
	IN PDRIVER_OBJECT	pDrvObj,
	IN PERAM_EXTENSION	pEramExt
 )
{
	/*�@���[�J���ϐ��@*/
	CM_RESOURCE_LIST	ResList;	/*�@���\�[�X���X�g�@*/
	BOOLEAN				bResConf;
	/*�@�A���}�b�v�@*/
	ExtUnmap(pEramExt);
	if (pEramExt->uOptflag.Bits.SkipReportUsage == 0)
	{
		/*�@�h���C�o�������(2000�ł͉������Ȃ��悤��)�@*/
		RtlZeroBytes(&ResList, sizeof(ResList));
		IoReportResourceUsage(NULL, pDrvObj, &ResList, sizeof(ResList), NULL, NULL, 0, FALSE, &bResConf);
		RtlZeroBytes(&(pEramExt->MapAdr), sizeof(pEramExt->MapAdr));
	}
}


/*�@EramReportEvent
		�V�X�e���C�x���g���O�o��
	����
		pIoObject	�f�o�C�X�I�u�W�F�N�gpDevObj �܂��� �h���C�o�I�u�W�F�N�gpDrvObj
		ntErrorCode	�C�x���gID
		pszString	�t�������� �ȗ���NULL
	�߂�l
		����
*/

BOOLEAN EramReportEvent(
	IN PVOID	pIoObject,
	IN NTSTATUS	ntErrorCode,
	IN PSTR		pszString
 )
{
	/*�@���[�J���ϐ��@*/
	ANSI_STRING		AnsiStr;
	UNICODE_STRING	UniStr;
	BOOLEAN			bStat;
	if ((pszString != NULL)&&
		(*pszString != L'\0'))
	{
		RtlInitAnsiString(&AnsiStr, pszString);
		/*�@UNICODE�����񉻂��ă_���v�@*/
		if (RtlAnsiStringToUnicodeString(&UniStr, &AnsiStr, TRUE) == STATUS_SUCCESS)
		{
			bStat = EramReportEventW(pIoObject, ntErrorCode, UniStr.Buffer);
			RtlFreeUnicodeString(&UniStr);
			return bStat;
		}
	}
	return EramReportEventW(pIoObject, ntErrorCode, NULL);
}


/*�@EramReportEventW
		�V�X�e���C�x���g���O�o��
	����
		pIoObject	�f�o�C�X�I�u�W�F�N�gpDevObj �܂��� �h���C�o�I�u�W�F�N�gpDrvObj
		ntErrorCode	�C�x���gID
		pwStr		�t��������(UNICODE) �ȗ���NULL
	�߂�l
		����
*/

BOOLEAN EramReportEventW(
	IN PVOID	pIoObject,
	IN NTSTATUS	ntErrorCode,
	IN PWSTR	pwStr
 )
{
	/*�@���[�J���ϐ��@*/
	PIO_ERROR_LOG_PACKET	pPacket;
	ULONG					uSize;
	UNICODE_STRING			UniStr;
	KdPrint(("EramReportEventW start, event:%ls\n", (PWSTR)((pwStr != NULL) ? pwStr : (PWSTR)(L""))));
	/*�@�p�P�b�g�T�C�Y�������@*/
	uSize = sizeof(IO_ERROR_LOG_PACKET);
	if (pwStr != NULL)	/*�@�t�������񂠂�@*/
	{
		RtlInitUnicodeString(&UniStr, pwStr);
		/*�@�p�P�b�g�T�C�Y���Z�@*/
		uSize += (UniStr.Length + sizeof(WCHAR));
	}
	if (uSize > ERROR_LOG_MAXIMUM_SIZE)		/*�@�����񂪒�������@*/
	{
		KdPrint(("String too long\n"));
		return FALSE;
	}
	/*�@�p�P�b�g�m�ہ@*/
	pPacket = IoAllocateErrorLogEntry(pIoObject, (UCHAR)uSize);
	if (pPacket == NULL)	/*�@�m�ێ��s�@*/
	{
		KdPrint(("IoAllocateErrorLogEntry failed\n"));
		return FALSE;
	}
	/*�@�W���f�[�^���������@*/
	RtlZeroBytes(pPacket, uSize);
	pPacket->ErrorCode = ntErrorCode;
	if (pwStr != NULL)		/*�@�t�������񂠂�@*/
	{
		/*�@�����񐔂�ݒ�@*/
		pPacket->NumberOfStrings = 1;
		/*�@������J�n�ʒu��ݒ�@*/
		pPacket->StringOffset = sizeof(IO_ERROR_LOG_PACKET);
		/*�@UNICODE��������R�s�[�@*/
		RtlCopyBytes(&(pPacket[1]), UniStr.Buffer, UniStr.Length);
	}
	/*�@���O�o�́@*/
	IoWriteErrorLogEntry(pPacket);
	KdPrint(("EramReportEventW end\n"));
	return TRUE;
}


/*�@ReadPool
		OS�Ǘ��������ǂݍ���
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		pIrpSp		�X�^�b�N���ւ̃|�C���^
		lpDest		�i�[�̈�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS ReadPool(
	IN PERAM_EXTENSION		pEramExt,
	IN PIRP					pIrp,
	IN PIO_STACK_LOCATION	pIrpSp,
	IN PUCHAR				lpDest
 )
{
	/*�@���[�J���ϐ��@*/
	PUCHAR lpSrc;
	lpSrc = (PUCHAR)((ULONG)pEramExt->pPageBase + (ULONG)pIrpSp->Parameters.Read.ByteOffset.LowPart);
	RtlCopyBytes(lpDest, lpSrc, pIrpSp->Parameters.Read.Length);
	return STATUS_SUCCESS;
}


/*�@WritePool
		OS�Ǘ���������������
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		pIrpSp		�X�^�b�N���ւ̃|�C���^
		lpSrc		�f�[�^�̈�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS WritePool(
	IN PERAM_EXTENSION		pEramExt,
	IN PIRP					pIrp,
	IN PIO_STACK_LOCATION	pIrpSp,
	IN PUCHAR				lpSrc
 )
{
	/*�@���[�J���ϐ��@*/
	PUCHAR lpDest;
	lpDest = (PUCHAR)((ULONG)pEramExt->pPageBase + (ULONG)pIrpSp->Parameters.Write.ByteOffset.LowPart);
	RtlCopyBytes(lpDest, lpSrc, pIrpSp->Parameters.Write.Length);
	return STATUS_SUCCESS;
}


/*�@ExtRead1
		OS�Ǘ��O�������ǂݍ���(check�Ȃ�)
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		pIrpSp		�X�^�b�N���ւ̃|�C���^
		lpDest		�i�[�̈�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS ExtRead1(
	IN PERAM_EXTENSION		pEramExt,
	IN PIRP					pIrp,
	IN PIO_STACK_LOCATION	pIrpSp,
	IN PUCHAR				lpDest
 )
{
	/*�@���[�J���ϐ��@*/
	PUCHAR	lpSrc;
	UINT	uLen;
	DWORD	eax, ebx;
	NTSTATUS ntStat;
	ULONG	uMemAdr;
	ASSERT(pEramExt->uExternalStart != 0);
	ASSERT(pEramExt->uExternalEnd != 0);
	/*�@Mutex�҂��@*/
	ExAcquireFastMutex(&(pEramExt->FastMutex));
	uLen = pIrpSp->Parameters.Read.Length;	/*�@�]���T�C�Y(�Z�N�^�T�C�Y�̔{��)�@*/
	/*�@�Z�N�^�ԍ����v�Z�@*/
	ebx = pIrpSp->Parameters.Read.ByteOffset.LowPart >> SECTOR_LOG2;
	/*�@�������ʒu���v�Z�@*/
	uMemAdr = pEramExt->uExternalStart + pIrpSp->Parameters.Read.ByteOffset.LowPart;
	ntStat = STATUS_SUCCESS;
	while (uLen != 0)
	{
		if (uMemAdr >= pEramExt->uExternalEnd)	/*�@���������𒴂��Ă���@*/
		{
			ntStat = STATUS_DISK_CORRUPT_ERROR;
			break;
		}
		/*�@64KB���蓖�ā@*/
		if (ExtNext1(pEramExt, &eax, &ebx) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ExtNext1");
			ntStat = STATUS_DISK_CORRUPT_ERROR;
			break;
		}
		lpSrc = (PUCHAR)((ULONG)(pEramExt->pExtPage + eax));
		/*�@�f�[�^�]���@*/
		RtlCopyBytes(lpDest, lpSrc, SECTOR);
		lpDest += SECTOR;
		uLen -= SECTOR;
		uMemAdr += SECTOR;
	}
	/*�@�A���}�b�v�@*/
	ExtUnmap(pEramExt);
	/*�@Mutex����@*/
	ExReleaseFastMutex(&(pEramExt->FastMutex));
	return ntStat;
}


/*�@ExtWrite1
		OS�Ǘ��O��������������(check�Ȃ�)
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		pIrpSp		�X�^�b�N���ւ̃|�C���^
		lpSrc		�f�[�^�̈�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS ExtWrite1(
	IN PERAM_EXTENSION		pEramExt,
	IN PIRP					pIrp,
	IN PIO_STACK_LOCATION	pIrpSp,
	IN PUCHAR				lpSrc
 )
{
	/*�@���[�J���ϐ��@*/
	PUCHAR lpDest;
	UINT	uLen;
	DWORD	eax, ebx;
	NTSTATUS ntStat;
	ULONG	uMemAdr;
	ASSERT(pEramExt->uExternalStart != 0);
	ASSERT(pEramExt->uExternalEnd != 0);
	/*�@Mutex�҂��@*/
	ExAcquireFastMutex(&(pEramExt->FastMutex));
	uLen = pIrpSp->Parameters.Write.Length;
	/*�@�Z�N�^�ԍ����v�Z�@*/
	ebx = pIrpSp->Parameters.Write.ByteOffset.LowPart >> SECTOR_LOG2;
	/*�@�������ʒu���v�Z�@*/
	uMemAdr = pEramExt->uExternalStart + pIrpSp->Parameters.Write.ByteOffset.LowPart;
	ntStat = STATUS_SUCCESS;
	while (uLen != 0)
	{
		if (uMemAdr >= pEramExt->uExternalEnd)	/*�@���������𒴂��Ă���@*/
		{
			ntStat = STATUS_DISK_CORRUPT_ERROR;
			break;
		}
		/*�@64KB���蓖�ā@*/
		if (ExtNext1(pEramExt, &eax, &ebx) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ExtNext1");
			ntStat = STATUS_DISK_CORRUPT_ERROR;
			break;
		}
		lpDest = (PUCHAR)((ULONG)(pEramExt->pExtPage + eax));
		/*�@�f�[�^�]���@*/
		RtlCopyBytes(lpDest, lpSrc, SECTOR);
		lpSrc += SECTOR;
		uLen -= SECTOR;
		uMemAdr += SECTOR;
	}
	/*�@�A���}�b�v�@*/
	ExtUnmap(pEramExt);
	/*�@Mutex����@*/
	ExReleaseFastMutex(&(pEramExt->FastMutex));
	return ntStat;
}


/*�@ExtNext1
		OS�Ǘ��O:�Y���Z�N�^�̊��蓖��(check�Ȃ���)
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		lpeax		�y�[�W���I�t�Z�b�g��Ԃ��̈�ւ̃|�C���^
		lpebx		�Z�N�^�ԍ��ւ̃|�C���^(+1�����)
	�߂�l
		����
*/

BOOLEAN ExtNext1(
	IN PERAM_EXTENSION	pEramExt,
	IN OUT LPDWORD		lpeax,
	IN OUT LPDWORD		lpebx
 )
{
	/*�@���[�J���ϐ��@*/
	DWORD eax, ebx, uMapAdr;
	ebx = *lpebx;
	/*�@�}�b�v���ׂ��o���N�ԍ����v�Z�@*/
	uMapAdr = (ebx >> EXT_PAGE_SEC_LOG2) << EXT_PAGE_SIZE_LOG2;
	/*�@�}�b�v�@*/
	if (ExtMap(pEramExt, uMapAdr) == FALSE)
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ExtMap");
		return FALSE;
	}
	/*�@�I�t�Z�b�g�Z�o�@*/
	eax = ebx & (EXT_PAGE_SECTOR - 1);
	eax <<= SECTOR_LOG2;
	/*�@�Z�N�^�ԍ���i�߂�@*/
	ebx++;
	*lpeax = eax;
	*lpebx = ebx;
	return TRUE;
}


/*�@ExtMap
		OS�Ǘ��O�������̃}�b�v
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		uMapAdr		�}�b�v���鑊�΃o�C�g�ʒu(64KB�P��)
	�߂�l
		����
*/

BOOLEAN ExtMap(
	IN PERAM_EXTENSION	pEramExt,
	IN ULONG			uMapAdr
 )
{
	/*�@���[�J���ϐ��@*/
	PHYSICAL_ADDRESS	MapAdr;
	if ((pEramExt->pExtPage == NULL)||			/*�@���}�b�v�@*/
		(pEramExt->uNowMapAdr != uMapAdr))	/*�@���݃}�b�v���̃y�[�W�ƈقȂ�@*/
	{
		/*�@���݂̃y�[�W���A���}�b�v�@*/
		ExtUnmap(pEramExt);
		/*�@�}�b�v�ʒu�␳�@*/
		MapAdr = pEramExt->MapAdr;
		if (MapAdr.LowPart == 0)		/*�@����ς݁@*/
		{
			KdPrint(("Already resource released\n"));
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_ALREADY_FREE, NULL);
			return FALSE;
		}
		MapAdr.LowPart += uMapAdr;
		/*�@�}�b�v(�L���b�V������)�@*/
		pEramExt->pExtPage = (PBYTE)MmMapIoSpace(MapAdr, EXT_PAGE_SIZE, TRUE);
		if (pEramExt->pExtPage == NULL)		/*�@���s�@*/
		{
			KdPrint(("MmMapIoSpace failed\n"));
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_MAP_FAILED, NULL);
			return FALSE;
		}
		pEramExt->uNowMapAdr = uMapAdr;
	}
	return TRUE;
}


/*�@ExtUnmap
		OS�Ǘ��O�������̃A���}�b�v
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID ExtUnmap(
	IN PERAM_EXTENSION	pEramExt
 )
{
	if (pEramExt->pExtPage != NULL)		/*�@�}�b�v���̃y�[�W����@*/
	{
		/*�@64KB�A���}�b�v�@*/
		MmUnmapIoSpace(pEramExt->pExtPage, EXT_PAGE_SIZE);
		pEramExt->pExtPage = NULL;
		pEramExt->uNowMapAdr = 0;
	}
}


/*�@ExtFilePendingRw
		�O���t�@�C���ǂݍ���(�ۗ�)
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		pIrpSp		�X�^�b�N���ւ̃|�C���^
		pTransAddr	�i�[�̈�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS ExtFilePendingRw(
	IN PERAM_EXTENSION		pEramExt,
	IN PIRP					pIrp,
	IN PIO_STACK_LOCATION	pIrpSp,
	IN PUCHAR				pTransAddr
 )
{
	//KdPrint(("ExtFilePendingRw start\n"));
	if (pEramExt->bThreadStop != 0)		/*�@�I���w���ς݁@*/
	{
		KdPrint(("stop sequence\n"));
		pIrp->IoStatus.Information = 0;
		return STATUS_DEVICE_NOT_READY;
	}
	if (pEramExt->pThreadObject == NULL)	/*�@�X���b�h�����@*/
	{
		KdPrint(("Thread not exist\n"));
		pIrp->IoStatus.Information = 0;
		return STATUS_DEVICE_NOT_READY;
	}
	/*�@I/O�ۗ��@*/
	IoMarkIrpPending(pIrp);
	pIrp->IoStatus.Status = STATUS_PENDING;
	/*�@�L���[�ɍڂ���@*/
	ExInterlockedInsertTailList(&(pEramExt->IrpList), &(pIrp->Tail.Overlay.ListEntry), &(pEramExt->IrpSpin));
	/*�@�Z�}�t�H1���炷�@*/
	KeReleaseSemaphore(&(pEramExt->IrpSem), 0, 1, FALSE);
	//KdPrint(("ExtFilePendingRw end\n"));
	return STATUS_PENDING;
}


/*�@EramRwThread
		�O���t�@�C�����[�h/���C�g�v���G���g��(DISPATCH_LEVEL)
	����
		pContext		�����n�����ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID EramRwThread(
	IN PVOID			pContext
 )
{
	/*�@���[�J���ϐ��@*/
	PERAM_EXTENSION		pEramExt;
	PIRP				pIrp;
	NTSTATUS			ntStat;
	PLIST_ENTRY			pIrpList;
	KdPrint(("EramRwThread start\n"));
	/*�@�擪�|�C���^�擾�@*/
	pEramExt = pContext;
	ASSERT(pEramExt != NULL);
	/*�@�D�扻�@*/
	KeSetPriorityThread(KeGetCurrentThread(), LOW_REALTIME_PRIORITY);		//�@�W����Prior8
	while (pEramExt->bThreadStop == 0)		/*�@�X���b�h�������@*/
	{
		//KdPrint(("Waiting\n"));
		/*�@�v���҂� �� �J�E���^�߂��@*/
		KeWaitForSingleObject(&(pEramExt->IrpSem), Executive, KernelMode, FALSE, NULL);
		if (pEramExt->bThreadStop != 0)		/*�@�X���b�h��~�v���@*/
		{
			KdPrint(("thread should stop\n"));
			break;
		}
		//KdPrint(("Wake\n"));
		/*�@IRP���X�g�̐擪���擾�@*/
		pIrpList = ExInterlockedRemoveHeadList(&(pEramExt->IrpList), &(pEramExt->IrpSpin));
		//KdPrint(("Get list\n"));
		if (pIrpList != NULL)		/*�@���X�g�L���@*/
		{
			ntStat = EramRwThreadIrp(pEramExt, pIrpList);
			//KdPrint(("EramRwThreadIrp return 0x%x\n", ntStat));
		}
	}
	/*�@�c���IRP���L�����Z���@*/
	for (;;)
	{
		/*�@IRP���X�g�̐擪���擾�@*/
		pIrpList = ExInterlockedRemoveHeadList(&(pEramExt->IrpList), &(pEramExt->IrpSpin));
		if (pIrpList == NULL)		/*�@����ȏ�͖����@*/
		{
			break;
		}
		/*�@IRP���擾�@*/
		pIrp = CONTAINING_RECORD(pIrpList, IRP, Tail.Overlay.ListEntry);
		ASSERT(pIrp != NULL);
		pIrp->IoStatus.Information = 0;
		pIrp->IoStatus.Status = STATUS_DEVICE_NOT_READY;
		/*�@I/O�����@*/
		IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	}
	if (pEramExt->hSection != NULL)
	{
		ExtFileUnmap(pEramExt);
		ZwClose(pEramExt->hSection);
		pEramExt->hSection = NULL;
	}
	if (pEramExt->hFile != NULL)
	{
		ZwClose(pEramExt->hFile);
		pEramExt->hFile = NULL;
	}
	KdPrint(("EramRwThread end\n"));
	PsTerminateSystemThread(STATUS_SUCCESS);
}


/*�@EramRwThreadIrp
		�O���t�@�C�����[�h/���C�g�v��(1IRP)
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrpList	IRP���X�g���ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS EramRwThreadIrp(
	PERAM_EXTENSION		pEramExt,
	PLIST_ENTRY			pIrpList
 )
{
	/*�@���[�J���ϐ��@*/
	PIRP				pIrp;
	PIO_STACK_LOCATION	pIrpSp;
	NTSTATUS			ntStat;
	PUCHAR				pTransAddr;
	//KdPrint(("EramRwThreadIrp start\n"));
	ASSERT(pEramExt != NULL);
	ASSERT(pIrpList != NULL);
	/*�@IRP���擾�@*/
	pIrp = CONTAINING_RECORD(pIrpList, IRP, Tail.Overlay.ListEntry);
	ASSERT(pIrp != NULL);
	pIrp->IoStatus.Information = 0;
	pTransAddr = NULL;
	if (pIrp->MdlAddress != NULL)	/*�@�A�h���X����@*/
	{
		/*�@�A�h���X�ϊ��@*/
		pTransAddr = MmGetSystemAddressForMdl(pIrp->MdlAddress);
	}
	if (pTransAddr == NULL)		/*�@�ϊ����s�@*/
	{
		KdPrint(("MmGetSystemAddressForMdl failed\n"));
		/*�@�X�e�[�^�X���Z�b�g�@*/
		pIrp->IoStatus.Status = STATUS_INVALID_PARAMETER;
		/*�@I/O�����@*/
		IoCompleteRequest(pIrp, IO_NO_INCREMENT);
		return STATUS_INVALID_PARAMETER;
	}
	pIrpSp = IoGetCurrentIrpStackLocation(pIrp);
	ASSERT(pIrpSp != NULL);
	switch (pIrpSp->MajorFunction)	/*�@�t�@���N�V�����ɂ�镪��@*/
	{
	case IRP_MJ_READ:				/*�@���[�h�@*/
		/*�@���[�h����ݒ�@*/
		pIrp->IoStatus.Information = pIrpSp->Parameters.Read.Length;
		ntStat = ExtFileRead1(pEramExt, pIrp, pIrpSp, pTransAddr);
		break;
	case IRP_MJ_WRITE:				/*�@���C�g�@*/
		/*�@���C�g����ݒ�@*/
		pIrp->IoStatus.Information = pIrpSp->Parameters.Write.Length;
		ntStat = ExtFileWrite1(pEramExt, pIrp, pIrpSp, pTransAddr);
		break;
	default:
		//KdPrint(("RW default\n"));
		ntStat = STATUS_SUCCESS;
		break;
	}
	/*�@�X�e�[�^�X���Z�b�g�@*/
	pIrp->IoStatus.Status = ntStat;
	/*�@I/O�����@*/
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	//KdPrint(("EramRwThreadIrp end\n"));
	return ntStat;
}


/*�@ExtFileRead1
		�O���t�@�C���ǂݍ���(check�Ȃ�)
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		pIrpSp		�X�^�b�N���ւ̃|�C���^
		lpDest		�i�[�̈�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS ExtFileRead1(
	IN PERAM_EXTENSION		pEramExt,
	IN PIRP					pIrp,
	IN PIO_STACK_LOCATION	pIrpSp,
	IN PUCHAR				lpDest
 )
{
	/*�@���[�J���ϐ��@*/
	PUCHAR	lpSrc;
	UINT	uLen;
	DWORD	eax, ebx;
	NTSTATUS ntStat;
	ASSERT(pEramExt != NULL);
	uLen = pIrpSp->Parameters.Read.Length;	/*�@�]���T�C�Y(�Z�N�^�T�C�Y�̔{��)�@*/
	/*�@�Z�N�^�ԍ����v�Z�@*/
	ebx = pIrpSp->Parameters.Read.ByteOffset.LowPart >> SECTOR_LOG2;
	ntStat = STATUS_SUCCESS;
	while (uLen != 0)
	{
		/*�@64KB���蓖�ā@*/
		if (ExtFileNext1(pEramExt, &eax, &ebx) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ExtFileNext1");
			ntStat = STATUS_DISK_CORRUPT_ERROR;
			break;
		}
		lpSrc = (PUCHAR)((ULONG)(pEramExt->pExtPage + eax));
		/*�@�f�[�^�]���@*/
		RtlCopyBytes(lpDest, lpSrc, SECTOR);
		lpDest += SECTOR;
		uLen -= SECTOR;
	}
	/*�@�A���}�b�v�@*/
	ExtFileUnmap(pEramExt);
	return ntStat;
}


/*�@ExtFileWrite1
		�O���t�@�C����������(check�Ȃ�)
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pIrp		IRP�p�P�b�g�ւ̃|�C���^
		pIrpSp		�X�^�b�N���ւ̃|�C���^
		lpSrc		�f�[�^�̈�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS ExtFileWrite1(
	IN PERAM_EXTENSION		pEramExt,
	IN PIRP					pIrp,
	IN PIO_STACK_LOCATION	pIrpSp,
	IN PUCHAR				lpSrc
 )
{
	/*�@���[�J���ϐ��@*/
	PUCHAR lpDest;
	UINT	uLen;
	DWORD	eax, ebx;
	NTSTATUS ntStat;
	ASSERT(pEramExt != NULL);
	uLen = pIrpSp->Parameters.Write.Length;
	/*�@�Z�N�^�ԍ����v�Z�@*/
	ebx = pIrpSp->Parameters.Write.ByteOffset.LowPart >> SECTOR_LOG2;
	ntStat = STATUS_SUCCESS;
	while (uLen != 0)
	{
		/*�@64KB���蓖�ā@*/
		if (ExtFileNext1(pEramExt, &eax, &ebx) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ExtFileNext1");
			ntStat = STATUS_DISK_CORRUPT_ERROR;
			break;
		}
		lpDest = (PUCHAR)((ULONG)(pEramExt->pExtPage + eax));
		/*�@�f�[�^�]���@*/
		RtlCopyBytes(lpDest, lpSrc, SECTOR);
		lpSrc += SECTOR;
		uLen -= SECTOR;
	}
	/*�@�A���}�b�v�@*/
	ExtFileUnmap(pEramExt);
	return ntStat;
}


/*�@ExtFileNext1
		�O���t�@�C��:�Y���Z�N�^�̊��蓖��(check�Ȃ���)
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		lpeax		�y�[�W���I�t�Z�b�g��Ԃ��̈�ւ̃|�C���^
		lpebx		�Z�N�^�ԍ��ւ̃|�C���^(+1�����)
	�߂�l
		����
*/

BOOLEAN ExtFileNext1(
	IN PERAM_EXTENSION	pEramExt,
	IN OUT LPDWORD		lpeax,
	IN OUT LPDWORD		lpebx
 )
{
	/*�@���[�J���ϐ��@*/
	DWORD eax, ebx, uMapAdr;
	ASSERT(pEramExt != NULL);
	ebx = *lpebx;
	/*�@�}�b�v���ׂ��o���N�ԍ����v�Z�@*/
	uMapAdr = (ebx >> EXT_PAGE_SEC_LOG2) << EXT_PAGE_SIZE_LOG2;
	/*�@�}�b�v�@*/
	if (ExtFileMap(pEramExt, uMapAdr) == FALSE)
	{
		KdPrint(("ExtFileMap failed, MapAdr=0x%x, sector=0x%x, SizeSec=0x%x, SizeBytes=0x%x\n", uMapAdr, ebx, (pEramExt->uAllSector << SECTOR_LOG2), (pEramExt->uSizeTotal << PAGE_SIZE_LOG2)));
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ExtFileMap");
		return FALSE;
	}
	/*�@�I�t�Z�b�g�Z�o�@*/
	eax = ebx & (EXT_PAGE_SECTOR - 1);
	eax <<= SECTOR_LOG2;
	/*�@�Z�N�^�ԍ���i�߂�@*/
	ebx++;
	*lpeax = eax;
	*lpebx = ebx;
	return TRUE;
}


/*�@ExtFileMap
		�O���t�@�C���̃}�b�v
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		uMapAdr		�}�b�v���鑊�΃o�C�g�ʒu(64KB�P��)
	�߂�l
		����
*/

BOOLEAN ExtFileMap(
	IN PERAM_EXTENSION	pEramExt,
	IN ULONG			uMapAdr
 )
{
	/*�@���[�J���ϐ��@*/
	LARGE_INTEGER llOfs;
	ULONG uView;
	NTSTATUS ntStat;
	ASSERT(pEramExt != NULL);
	if ((pEramExt->pExtPage == NULL)||			/*�@���}�b�v�@*/
		(pEramExt->uNowMapAdr != uMapAdr))		/*�@���݃}�b�v���̃y�[�W�ƈقȂ�@*/
	{
		/*�@���݂̃y�[�W���A���}�b�v�@*/
		ExtFileUnmap(pEramExt);
		/*�@�}�b�v�ʒu�����@*/
		llOfs.QuadPart = (LONGLONG)uMapAdr;
		uView = ((pEramExt->uSizeTotal << PAGE_SIZE_LOG2) - uMapAdr);
		if (uView > EXT_PAGE_SIZE)
		{
			uView = EXT_PAGE_SIZE;
		}
		/*�@�}�b�v(�L���b�V������)�@*/
		ntStat = ZwMapViewOfSection(pEramExt->hSection, NtCurrentProcess(), &(pEramExt->pExtPage), 0, uView, &llOfs, &uView, ViewShare, 0, PAGE_READWRITE);
		if (ntStat != STATUS_SUCCESS)		/*�@���s�@*/
		{
			KdPrint(("ZwMapViewOfSection failed, 0x%x, MapAdr=0x%x, size=0x%x\n", ntStat, uMapAdr, uView));
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAP_EXT_FILE, NULL);
			return FALSE;
		}
		ASSERT((pEramExt->pExtPage) != NULL);
		pEramExt->uNowMapAdr = uMapAdr;
	}
	return TRUE;
}


/*�@ExtFileUnmap
		�O���t�@�C���̃A���}�b�v
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID ExtFileUnmap(
	IN PERAM_EXTENSION	pEramExt
 )
{
	/*�@���[�J���ϐ��@*/
	NTSTATUS ntStat;
	ASSERT(pEramExt != NULL);
	if (pEramExt->pExtPage == NULL)		/*�@�}�b�v���̃y�[�W�Ȃ��@*/
	{
		return;
	}
	/*�@64KB�A���}�b�v�@*/
	ntStat = ZwUnmapViewOfSection(NtCurrentProcess(), pEramExt->pExtPage);
	pEramExt->pExtPage = NULL;
	pEramExt->uNowMapAdr = 0;
	if (ntStat != STATUS_SUCCESS)
	{
		KdPrint(("ZwMapViewOfSection failed, 0x%x\n", ntStat));
	}
}


/*�@EramShutdown
		�V���b�g�_�E���v���G���g��
	����
		pDevObj	���u�I�u�W�F�N�g�ւ̃|�C���^
		pIrp	IRP�p�P�b�g�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS EramShutdown(
	IN PDEVICE_OBJECT	pDevObj,
	IN PIRP				pIrp
 )
{
	/*�@���[�J���ϐ��@*/
	PERAM_EXTENSION pEramExt;
	LARGE_INTEGER  	llTime;
	KdPrint(("EramShutdown start\n"));
	pEramExt = pDevObj->DeviceExtension;
	/*�@�X���b�h�I����ʒm�@*/
	pEramExt->bThreadStop = TRUE;
	if (pEramExt->pThreadObject != NULL)		/*�@�X���b�h���݁@*/
	{
		/*�@�Z�}�t�H1���炷�@*/
		KeReleaseSemaphore(&(pEramExt->IrpSem), 0, 1, TRUE);
		/*�@�X���b�h�I���҂�5�b�@*/
		llTime.QuadPart = (LONGLONG)(-5 * 10000000);
		KeWaitForSingleObject(&(pEramExt->pThreadObject), Executive, KernelMode, FALSE, &llTime);
		/*�@�X���b�h�̎Q�ƃJ�E���g�����炷�@*/
		ObDereferenceObject(&(pEramExt->pThreadObject));
		pEramExt->pThreadObject = NULL;
	}
	/*�@�O���t�@�C���N���[�Y�@*/
	if (pEramExt->hSection != NULL)
	{
		KdPrint(("File section close\n"));
		ExtFileUnmap(pEramExt);
		ZwClose(pEramExt->hSection);
		pEramExt->hSection = NULL;
	}
	if (pEramExt->hFile != NULL)
	{
		ZwClose(pEramExt->hFile);
		pEramExt->hFile = NULL;
	}
	/*�@�������Z�b�g�@*/
	pIrp->IoStatus.Status = STATUS_SUCCESS;
	pIrp->IoStatus.Information = 0;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	KdPrint(("EramShutdown end\n"));
	return STATUS_SUCCESS;
}


//------  ����ȍ~�͏��������Ɏg�p����֐��Q


/*�@DriverEntry
		�h���C�o���������̃G���g���|�C���g
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pRegPath	���W�X�g���L�[�ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS DriverEntry(
	IN OUT PDRIVER_OBJECT	pDrvObj,
	IN PUNICODE_STRING		pRegPath
 )
{
	/*�@���[�J���ϐ��@*/
	NTSTATUS		ntStat;
	UNICODE_STRING	RegParam;		/*�@UNICODE��p�������W�X�g���p�X�@*/
	UNICODE_STRING	RegParamAdd;	/*�@UNICODE��p�������W�X�g���p�X�@*/
	PVOID			pPool;
	PFAT_ID			pFatId;			/*�@BPB��Ɨ̈�@*/
	KdPrint(("DriverEntry start\n"));
	/*�@���W�X�g���p�X�ő咷���擾�@*/
	RegParam.MaximumLength = (WORD)(pRegPath->Length + sizeof(SUBKEY_WSTRING));
	/*�@��Ɨp�������m�ہ@*/
	pPool = ExAllocatePool(PagedPool, sizeof(*pFatId) + RegParam.MaximumLength);
	if (pPool == NULL)		/*�@�m�ێ��s�@*/
	{
		KdPrint(("ExAllocatePool failed\n"));
		EramReportEvent(pDrvObj, ERAMNT_ERROR_WORK_ALLOC_FAILED, NULL);
		/*�@�G���[��Ԃ��@*/
		return STATUS_INSUFFICIENT_RESOURCES;
	}
	/*�@�|�C���^�ݒ�@*/
	pFatId = (PFAT_ID)pPool;
	RegParam.Buffer = (PWSTR)(&(pFatId[1]));
	/*�@���W�X�g���L�[��������R�s�[�@*/
	RtlCopyUnicodeString(&RegParam, pRegPath);
	/*�@���W�X�g���T�u�L�[��������R�s�[�@*/
	RtlInitUnicodeString(&RegParamAdd, (PWSTR)SUBKEY_WSTRING);
	if (RtlAppendUnicodeStringToString(&RegParam, &RegParamAdd) != STATUS_SUCCESS)	/*�@�������s�@*/
	{
		KdPrint(("RtlAppendUnicodeStringToString failed\n"));
		EramReportEvent(pDrvObj, ERAMNT_ERROR_REG_KEY_APPEND_FAILED, NULL);
		/*�@��Ɨp������������@*/
		ExFreePool(pPool);
		/*�@�G���[��Ԃ��@*/
		return STATUS_INSUFFICIENT_RESOURCES;
	}
	/*�@FatId�\���̂̏������@*/
	InitFatId(pFatId);
	/*�@�h���C�o�̃G���g���|�C���g���������@*/
	pDrvObj->MajorFunction[IRP_MJ_CREATE] = EramCreateClose;
	pDrvObj->MajorFunction[IRP_MJ_CLOSE] = EramCreateClose;
	pDrvObj->MajorFunction[IRP_MJ_READ] = EramReadWrite;
	pDrvObj->MajorFunction[IRP_MJ_WRITE] = EramReadWrite;
	pDrvObj->MajorFunction[IRP_MJ_DEVICE_CONTROL] = EramDeviceControl;
	pDrvObj->MajorFunction[IRP_MJ_SHUTDOWN] = EramShutdown;
	/*�@������̃G���g�����������@*/
	pDrvObj->DriverUnload = EramUnloadDriver;
	/*�@RAM�f�B�X�N���������@*/
	ntStat = EramInitDisk(pDrvObj, pFatId, &RegParam);
	ASSERT(pPool != NULL);
	/*�@��Ɨp������������@*/
	ExFreePool(pPool);
	KdPrint(("DriverEntry end\n"));
	/*�@�������I���@*/
	return ntStat;
}


/*�@InitFatId
		FatId�\���̂̏�����
	����
		pFatId		FAT-ID�\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID InitFatId(
	IN	PFAT_ID		pFatId
 )
{
	KdPrint(("InitFatId start\n"));
	RtlZeroBytes(pFatId, sizeof(*pFatId));
	pFatId->BPB.wNumSectorByte = SECTOR;				/*�@�Z�N�^�o�C�g��(BPB, =SECTOR)�@*/
	pFatId->BPB.byAllocUnit = 1024 / SECTOR;			/*�@�A���P�[�V�������j�b�g(alloc, =1024/SECTOR)�@*/
	pFatId->BPB.wNumResvSector = 1;						/*�@�\��Z�N�^��(=1)�@*/
	pFatId->BPB.byNumFat = 1;							/*�@FAT��(=1)�@*/
	pFatId->BPB.wNumDirectory = 128;					/*�@���[�g�f�B���N�g���G���g����(dir, =128)�@*/
	pFatId->BPB.byMediaId = RAMDISK_MEDIA_TYPE;			/*�@���f�B�AID(media, =f8)�@*/
	pFatId->BPB_ext.bsSecPerTrack = 1;					/*�@1�o���N������̃Z�N�^��(=PAGE_SECTOR)�@*/
	pFatId->BPB_ext.bsHeads = 1;						/*�@�w�b�h��(=1)�@*/
	pFatId->BPB_fat32.dwRootCluster = 2;				/*�@���[�g�f�B���N�g���̊J�n�N���X�^�@*/
	pFatId->BPB_fat32.wFsInfoSector = 1;				/*�@FSINFO�̃Z�N�^�@*/
	pFatId->BPB_fat32.wBackupBootSector = 0xffff;		/*�@�o�b�N�A�b�v�u�[�g�Z�N�^�@*/
	KdPrint(("InitFatId end\n"));
}


/*�@EramInitDisk
		ERAM������
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
		pRegParam	���W�X�g���p�X������ւ̃|�C���^
	�߂�l
		����
*/

NTSTATUS EramInitDisk(
	IN PDRIVER_OBJECT	pDrvObj,
	IN PFAT_ID			pFatId,
	IN PUNICODE_STRING	pRegParam
 )
{
	/*�@���[�J���ϐ��@*/
	UNICODE_STRING	NtDevName;		/*�@NT�f�o�C�X�� "\Device\Eram"�@*/
	UNICODE_STRING	Win32Name;		/*�@Win32�� "\DosDevices\Z:"�@*/
	UNICODE_STRING	DrvStr;			/*�@�h���C�u�����@*/
	WCHAR			DrvBuf[3];		/*�@�h���C�u�����擾�p�o�b�t�@�@*/
	PDEVICE_OBJECT	pDevObj = NULL;
	PERAM_EXTENSION	pEramExt = NULL;
	NTSTATUS		ntStat;
	ULONG			uMemSize;
	DEVICE_TYPE		dType;
	KdPrint(("EramInitDisk start\n"));
	/*�@�X���b�v�\�f�o�C�X�ɂ��邩�ǂ����m�F�@*/
	dType = CheckSwapable(pRegParam);
	/*�@��������������@*/
	RtlInitUnicodeString(&NtDevName, (PWSTR)NT_DEVNAME);
	/*�@�f�o�C�X���������ւ��邩�ǂ����m�F�@*/
	CheckDeviceName(pRegParam, &NtDevName);
	/*�@�f�o�C�X�쐬�@*/
	ntStat = IoCreateDevice(pDrvObj, sizeof(*pEramExt), &NtDevName, dType, 0, FALSE, &pDevObj);
	if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
	{
		KdPrint(("IoCreateDevice failed, 0x%x\n", ntStat));
{
	CHAR szBuf[128];
	sprintf(szBuf, "IoCreateDevice failed, 0x%x", ntStat);
	EramReportEvent(pDrvObj, ERAMNT_ERROR_FUNCTIONERROR, szBuf);	//@@@
	sprintf(szBuf, "Device is \"%ls\"", NtDevName.Buffer);
	EramReportEvent(pDrvObj, ERAMNT_ERROR_FUNCTIONERROR, szBuf);	//@@@
}

		EramReportEvent(pDrvObj, ERAMNT_ERROR_CREATE_DEVICE_FAILED, NULL);
		return ntStat;
	}
	/*�@���|�C���^�擾�@*/
	pEramExt = (PERAM_EXTENSION)(pDevObj->DeviceExtension);
	/*�@ERAM���̈揉�����@*/
	RtlZeroBytes(pEramExt, sizeof(*pEramExt));
	/*�@�h���C�u�����o�b�t�@�N���A�@*/
	DrvBuf[0] = UNICODE_NULL;
	RtlInitUnicodeString(&DrvStr, DrvBuf);
	DrvStr.MaximumLength = sizeof(DrvBuf);
	/*�@���W�X�g��������擾�@*/
	CheckSwitch(pEramExt, pFatId, pRegParam, &DrvStr);
	pEramExt->uOptflag.Bits.Swapable = (BYTE)((dType == FILE_DEVICE_DISK) ? 1 : 0);
	/*�@�f�o�C�X��񏉊����@*/
	pDevObj->Flags |= DO_DIRECT_IO;
	pDevObj->AlignmentRequirement = FILE_WORD_ALIGNMENT;
	pEramExt->pDevObj = pDevObj;
	if (pEramExt->uOptflag.Bits.External != 0)				/*�@OS�Ǘ��O�������g�p�@*/
	{
		if (GetExternalStart(pDrvObj, pEramExt) == FALSE)	/*�@OS�Ǘ��O�����������@*/
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_NOT_DETECTED, NULL);
			return STATUS_INSUFFICIENT_RESOURCES;
		}
		if ((pEramExt->uOptflag.Bits.SkipExternalCheck == 0)&&	/*�@�`�F�b�N��΂��Ȃ��@*/
			(CheckExternalSize(pDrvObj, pEramExt) == FALSE))	/*�@�`�F�b�N���s�@*/
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "CheckExternalSize");
			return STATUS_INSUFFICIENT_RESOURCES;
		}
		/*�@�~���[�e�b�N�X�������@*/
		ExInitializeFastMutex(&(pEramExt->FastMutex));
	}
	/*�@�������m�ہ@*/
	uMemSize = pEramExt->uSizeTotal << PAGE_SIZE_LOG2;
	if (pEramExt->uSizeTotal < DISKMINPAGE)		/*�@�������Ȃ��@*/
	{
		KdPrint(("Memory size too small, %d\n", pEramExt->uSizeTotal));
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_DISK_SIZE_TOO_SMALL, NULL);
		ntStat = STATUS_INSUFFICIENT_RESOURCES;
		goto EramInitDiskExit;
	}
	/*�@�������̈�m�ہ@*/
	ntStat = MemSetup(pDrvObj, pEramExt, pFatId, uMemSize);
	if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "MemSetup");
		goto EramInitDiskExit;
	}
	/*�@FAT�t�H�[�}�b�g�@*/
	if (EramFormatFat(pEramExt, pFatId) == FALSE)
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "EramFormatFat");
		ntStat = STATUS_INSUFFICIENT_RESOURCES;
		goto EramInitDiskExit;
	}
	/*�@ERAM���ݒ�@*/
	pEramExt->bsHiddenSecs = pFatId->BPB_ext.bsHiddenSecs;
	/*�@Win32�f�o�C�X���̈�m�ہ@*/
	pEramExt->Win32Name.Buffer = ExAllocatePool(PagedPool, (sizeof(WIN32_PATH) + sizeof(DEFAULT_DRV)));
	if (pEramExt->Win32Name.Buffer == NULL)		/*�@�m�ێ��s�@*/
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_DEVICE_NAME_ALLOC_FAILED, NULL);
		ntStat = STATUS_INSUFFICIENT_RESOURCES;
		goto EramInitDiskExit;
	}
	pEramExt->Win32Name.MaximumLength = sizeof(WIN32_PATH) + sizeof(DEFAULT_DRV);
	/*�@�h���C�u������s���̏ꍇ��Z:�ɂ���@*/
	if (DrvStr.Buffer[0] == UNICODE_NULL)
	{
		DrvStr.Buffer[0] = L'Z';
	}
	DrvStr.Buffer[1] = L':';
	DrvStr.Buffer[2] = UNICODE_NULL;
	DrvStr.Length = sizeof(DEFAULT_DRV) - sizeof(WCHAR);	/*�@"Z:"��2�����@*/
	KdPrint(("Drive %ls\n", DrvStr.Buffer));
	/*�@Win32�f�o�C�X�������@*/
	RtlInitUnicodeString(&Win32Name, (PWSTR)WIN32_PATH);
	RtlCopyUnicodeString(&(pEramExt->Win32Name), &Win32Name);
	RtlAppendUnicodeStringToString(&(pEramExt->Win32Name), &DrvStr);
	/*�@�����N�쐬�@*/
	ntStat = IoCreateSymbolicLink(&(pEramExt->Win32Name), &NtDevName);
	if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_CREATE_SYMBOLIC_LINK_FAILED, NULL);
		/*�@Win32���̈����@*/
		ExFreePool(pEramExt->Win32Name.Buffer);
		pEramExt->Win32Name.Buffer = NULL;
	}
EramInitDiskExit:	/*�@�G���[���G���g���@*/
	if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
	{
		if (pEramExt->uOptflag.Bits.External != 0)	/*�@OS�Ǘ��O�������g�p�@*/
		{
			/*�@��������������@*/
			ReleaseMemResource(pDrvObj, pEramExt);
		}
		if (pDevObj != NULL)	/*�@�f�o�C�X�쐬�ρ@*/
		{
			/*�@�f�o�C�X�폜�@*/
			EramUnloadDevice(pDrvObj, pDevObj, pEramExt);
		}
	}
	KdPrint(("EramInitDisk end\n"));
	return ntStat;
}


/*�@MemSetup
		�������̈�̊m��
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
		uMemSize	�v����������
	�߂�l
		����
*/

NTSTATUS MemSetup(
	IN PDRIVER_OBJECT	pDrvObj,
	IN PERAM_EXTENSION	pEramExt,
	IN PFAT_ID			pFatId,
	IN ULONG			uMemSize
 )
{
	/*�@���[�J���ϐ��@*/
	FILE_END_OF_FILE_INFORMATION	EofInfo;
	NTSTATUS						ntStat;
	IO_STATUS_BLOCK					IoStat;
	OBJECT_ATTRIBUTES				ObjAttr;
	UNICODE_STRING					uniStr;
	HANDLE							hThread;
	KdPrint(("MemSetup start\n"));
	if (pEramExt->uOptflag.Bits.External != 0)	/*�@OS�Ǘ��O�������@*/
	{
		/*�@�����g�p��ʒm�@*/
		if (ExtReport(pDrvObj, pEramExt) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ExtReport");
			return STATUS_INSUFFICIENT_RESOURCES;
		}
		return STATUS_SUCCESS;
	}
	if (pEramExt->uOptflag.Bits.UseExtFile != 0)	/*�@�O���t�@�C���g�p�@*/
	{
		/*�@�Ƃ肠�����t�@�C������p�Ӂ@*/
		RtlInitUnicodeString(&uniStr, (PWSTR)(pFatId->wszExtFile));
		InitializeObjectAttributes(&ObjAttr, &uniStr, OBJ_CASE_INSENSITIVE, NULL, NULL);
		/*�@�t�@�C���J���@*/
		ntStat = ZwCreateFile(&(pEramExt->hFile),
						GENERIC_READ | GENERIC_WRITE,
						&ObjAttr,
						&IoStat,
						NULL,
						FILE_ATTRIBUTE_SYSTEM,
						FILE_SHARE_READ,
						FILE_OVERWRITE_IF,
						FILE_NON_DIRECTORY_FILE | FILE_DELETE_ON_CLOSE,
						NULL,
						0
						);
		if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
		{
			KdPrint(("ZwCreateFile failed, 0x%x\n", ntStat));
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_CREATE_EXT_FILE, NULL);
			return ntStat;
		}
		/*�@�t�@�C���T�C�Y�m�ہ@*/
		EofInfo.EndOfFile.QuadPart = (LONGLONG)uMemSize;
		ntStat = ZwSetInformationFile(pEramExt->hFile, &IoStat, &EofInfo, sizeof(EofInfo), FileEndOfFileInformation);
		if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
		{
			KdPrint(("ZwSetInformationFile failed, 0x%x\n", ntStat));
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_SET_INFO_EXT_FILE, NULL);
			return ntStat;
		}
		/*�@�}�b�s���O�I�u�W�F�N�g�쐬�@*/
		ntStat = ZwCreateSection(&(pEramExt->hSection), SECTION_ALL_ACCESS, NULL, NULL, PAGE_READWRITE, SEC_COMMIT, pEramExt->hFile);
		if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
		{
			KdPrint(("ZwCreateSection failed, 0x%x\n", ntStat));
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_CREATE_EXT_FILE_SECTION, NULL);
			return ntStat;
		}
		/*�@�X�s�����b�N�������@*/
		KeInitializeSpinLock(&(pEramExt->IrpSpin));
		/*�@���X�g�������@*/
		InitializeListHead(&(pEramExt->IrpList));
		/*�@�Z�}�t�H�������@*/
		KeInitializeSemaphore(&(pEramExt->IrpSem), 0, MAXLONG);
		/*�@�V�X�e���X���b�h�쐬�@*/
		ntStat = PsCreateSystemThread(&hThread, THREAD_ALL_ACCESS, NULL, NULL, NULL, EramRwThread, pEramExt);
		if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
		{
			KdPrint(("PsCreateSystemThread failed\n"));
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_CREATE_THREAD, NULL);
			return ntStat;
		}
		/*�@�X���b�h�I�u�W�F�N�g�擾�@*/
		ntStat = ObReferenceObjectByHandle(hThread, THREAD_ALL_ACCESS, NULL, KernelMode, &(pEramExt->pThreadObject), NULL);
		if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
		{
			KdPrint(("ObReferenceObjectByHandle failed\n"));
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_GET_THREAD_OBJECT, NULL);
			return ntStat;
		}
		/*�@�X���b�h�n���h������@*/
		ZwClose(hThread);
		/*�@�V���b�g�_�E���ʒm��L�����@*/
		IoRegisterShutdownNotification(pEramExt->pDevObj);
		return STATUS_SUCCESS;
	}
	/*�@OS�Ǘ��������g�p�@*/
	if (OsAlloc(pDrvObj, pEramExt, uMemSize) == FALSE)
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "OsAlloc");
		return STATUS_INSUFFICIENT_RESOURCES;
	}
	KdPrint(("MemSetup end\n"));
	return STATUS_SUCCESS;
}


/*�@OsAlloc
		OS�Ǘ��������̊m��
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		uMemSize	�v����������
	�߂�l
		����
*/

BOOLEAN OsAlloc(
	IN PDRIVER_OBJECT	pDrvObj,
	IN PERAM_EXTENSION	pEramExt,
	IN ULONG			uMemSize
 )
{
	/*�@���[�J���ϐ��@*/
	POOL_TYPE	fPool;
	fPool = (pEramExt->uOptflag.Bits.NonPaged != 0) ? NonPagedPool : PagedPool;
	pEramExt->pPageBase = ExAllocatePool(fPool, uMemSize);
	if (pEramExt->pPageBase == NULL)	/*�@�m�ێ��s�@*/
	{
		KdPrint(("ExAllocatePool failed, %d bytes, nonpaged=%d\n", uMemSize, (UINT)(pEramExt->uOptflag.Bits.NonPaged)));
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_DISK_ALLOC_FAILED, NULL);
		CalcAvailSize(pDrvObj, fPool, uMemSize);
		return FALSE;
	}
	return TRUE;
}


/*�@CalcAvailSize
		�m�ۂł������ȃ������ʂ̕�
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		fPool		�������^�C�v
		uMemSize	�v����������
	�߂�l
		�Ȃ�
*/

VOID CalcAvailSize(
	IN PDRIVER_OBJECT	pDrvObj,
	IN POOL_TYPE		fPool,
	IN ULONG			uMemSize
 )
{
	/*�@���[�J���ϐ��@*/
	PVOID			pBuf;
	UNICODE_STRING	UniStr;
	WCHAR			wcBuf[32];
	pBuf = NULL;
	while ((uMemSize > (DISKMINPAGE << PAGE_SIZE_LOG2))&&(pBuf == NULL))
	{
		/*�@�������m�ہ@*/
		uMemSize -= (DISKMINPAGE << PAGE_SIZE_LOG2);
		pBuf = ExAllocatePool(fPool, uMemSize);
	}
	if (pBuf == NULL)		/*�@�m�ێ��s�@*/
	{
		return;
	}
	/*�@����������@*/
	ExFreePool(pBuf);
	/*�@75%���炢�ɐ����@*/
	uMemSize = (uMemSize >> 2) * 3;
	/*�@�������ʂ�񍐁@*/
	wcBuf[0] = UNICODE_NULL;
	RtlInitUnicodeString(&UniStr, wcBuf);
	UniStr.MaximumLength = sizeof(wcBuf);
	if (RtlIntegerToUnicodeString(uMemSize >> 10, 10, &UniStr) == STATUS_SUCCESS)
	{
		EramReportEventW(pDrvObj, ERAMNT_INF_MEMORY_SIZE, UniStr.Buffer);
	}
}


/*�@CheckSwapable
		���W�X�g���̎Q��:�X���b�v�\�f�o�C�X�ɂ��邩�ǂ����̑I��
	����
		pRegParam	���W�X�g���p�X������ւ̃|�C���^
	�߂�l
		�f�o�C�X�^�C�v
	���W�X�g���p�����[�^
		Option			�I�v�V����
*/

DEVICE_TYPE CheckSwapable(
	IN PUNICODE_STRING		pRegParam
 )
{
	/*�@���[�J���ϐ��@*/
	RTL_QUERY_REGISTRY_TABLE	ParamTable[2];
	ULONG			Option,		defOption = 0;
	NTSTATUS		ntStat;
	ERAM_OPTFLAG	uOptflag;
	KdPrint(("CheckSwapable start\n"));
	/*�@���W�X�g���m�F�̈揉�����@*/
	RtlZeroBytes(&(ParamTable[0]), sizeof(ParamTable));
	/*�@�ꊇ�₢���킹�̈揉����(�Ō��NULL)�@*/
	ParamTable[0].Flags = RTL_QUERY_REGISTRY_DIRECT;
	ParamTable[0].DefaultType = REG_DWORD;
	ParamTable[0].DefaultLength = sizeof(ULONG);
	ParamTable[0].Name = (PWSTR)L"Option";
	ParamTable[0].EntryContext = &Option;
	ParamTable[0].DefaultData = &defOption;
	/*�@���W�X�g���l�₢���킹�@*/
	ntStat = RtlQueryRegistryValues(RTL_REGISTRY_ABSOLUTE | RTL_REGISTRY_OPTIONAL, pRegParam->Buffer, &(ParamTable[0]), NULL, NULL);
	if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
	{
		KdPrint(("Warning:RtlQueryRegistryValues failed\n"));
		/*�@����l���̗p�@*/
		Option = defOption;
	}
	uOptflag.dwOptflag = Option;
	if (uOptflag.Bits.Swapable != 0)		/*�@�X���b�v�\�Ȑݒ�@*/
	{
		KdPrint(("CheckSwapable end, local disk\n"));
		/*�@�X���b�v����Ȃ��悤���b�N����@*/
#pragma warning(disable : 4054)
		MmLockPagableCodeSection((PVOID)EramCreateClose);
#pragma warning(default : 4054)
		/*�@���[�J���f�B�X�N�����ɂ���:�X���b�v�\�@*/
		return FILE_DEVICE_DISK;
	}
	/*�@RAM�f�B�X�N�����ɂ���@*/
	KdPrint(("CheckSwapable end, virtual disk\n"));
	return FILE_DEVICE_VIRTUAL_DISK;
}


/*�@CheckDeviceName
		���W�X�g���̎Q��(�f�o�C�X��)
	����
		pRegParam	���W�X�g���p�X������ւ̃|�C���^
		pNtDevName	NT�f�o�C�X���ւ̃|�C���^
	�߂�l
		�Ȃ�
	���W�X�g���p�����[�^
		DeviceName	�f�o�C�X��
*/

VOID CheckDeviceName(
	IN PUNICODE_STRING		pRegParam,
	IN OUT PUNICODE_STRING	pNtDevName
 )
{
	/*�@���[�J���ϐ��@*/
	static WCHAR wszDef[] = L"";
	static WCHAR wszDev[32] = L"";		/*�@\\Device\\�`�@*/
	RTL_QUERY_REGISTRY_TABLE	ParamTable[2];
	NTSTATUS		ntStat;
	UNICODE_STRING	UniDev;
	KdPrint(("CheckDeviceName start\n"));
	/*�@�₢���킹�p�����l�����@*/
	RtlInitUnicodeString(&UniDev, wszDev);
	UniDev.MaximumLength = sizeof(wszDev);
	/*�@���W�X�g���m�F�̈揉�����@*/
	RtlZeroBytes(&ParamTable, sizeof(ParamTable));
	/*�@�ꊇ�₢���킹�̈揉����(�Ō��NULL)�@*/
	ParamTable[0].Flags = RTL_QUERY_REGISTRY_DIRECT;
	ParamTable[0].Name = (PWSTR)L"DeviceName";
	ParamTable[0].EntryContext = &UniDev;
	ParamTable[0].DefaultType = REG_SZ;
	ParamTable[0].DefaultData = (LPWSTR)wszDef;
	ParamTable[0].DefaultLength = sizeof(wszDef);
	/*�@���W�X�g���l�ꊇ�₢���킹�@*/
	ntStat = RtlQueryRegistryValues(RTL_REGISTRY_ABSOLUTE | RTL_REGISTRY_OPTIONAL, pRegParam->Buffer, &(ParamTable[0]), NULL, NULL);
	if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
	{
		KdPrint(("Warning:RtlQueryRegistryValues failed, 0x%x\n", ntStat));
		return;
	}
	if (UniDev.Length == 0)		/*�@�w�薳���@*/
	{
		KdPrint(("No value set\n"));
		return;
	}
	KdPrint(("CheckDeviceName end, device \"%ls\"\n", UniDev.Buffer));
	*pNtDevName = UniDev;
}


/*�@CheckSwitch
		���W�X�g���̎Q�ƂƃI�v�V�����ݒ�
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
		pRegParam	���W�X�g���p�X������ւ̃|�C���^
		pDrvStr		�h���C�u�����ւ̃|�C���^
	�߂�l
		�Ȃ�
	���W�X�g���p�����[�^
		AllocUnit		�N���X�^�T�C�Y
		DriveLetter		�h���C�u�w��
		RootDirEntries	���[�g�f�B���N�g���G���g����
		MediaId			���f�B�AID
		Option			�I�v�V����
		Page			4KB�y�[�W��
*/

VOID CheckSwitch(
	IN PERAM_EXTENSION		pEramExt,
	IN PFAT_ID				pFatId,
	IN PUNICODE_STRING		pRegParam,
	IN OUT PUNICODE_STRING	pDrvStr
 )
{
	/*�@���[�J���ϐ��@*/
	PRTL_QUERY_REGISTRY_TABLE		pParamTable;
	ULONG			AllocUnit,		defAllocUnit = 1024 / SECTOR;
	ULONG			RootDir,		defRootDir = 128;
	ULONG			MediaId,		defMediaId = RAMDISK_MEDIA_TYPE;
	ULONG			Option,			defOption = 0;
	ULONG			Page, 			defPage = DISKMINPAGE;
	ULONG			ExtStart,		defExtStart = 0;
	UINT			loopi;
	ULONGLONG		ulPageT;
	NTSTATUS		ntStat;
	BOOLEAN			bDefault;
	KdPrint(("CheckSwitch start\n"));
	bDefault = TRUE;
	#define	REGOPTNUM	(8)
	#define	REGOPTSIZE	(REGOPTNUM * sizeof(*pParamTable))
	/*�@�₢���킹�p�������m�ہ@*/
	pParamTable = ExAllocatePool(PagedPool, REGOPTSIZE);
	if (pParamTable != NULL)	/*�@�����@*/
	{
		/*�@���W�X�g���m�F�̈揉�����@*/
		RtlZeroBytes(pParamTable, REGOPTSIZE);
		/*�@�ꊇ�₢���킹�̈揉����(�Ō��NULL)�@*/
		for (loopi=0; loopi<(REGOPTNUM-1); loopi++)
		{
			pParamTable[loopi].Flags = RTL_QUERY_REGISTRY_DIRECT;
			pParamTable[loopi].DefaultType = REG_DWORD;
			pParamTable[loopi].DefaultLength = sizeof(ULONG);
		}
		pParamTable[0].Name = (PWSTR)L"AllocUnit";
		pParamTable[0].EntryContext = &AllocUnit;
		pParamTable[0].DefaultData = &defAllocUnit;
		pParamTable[1].Name = (PWSTR)L"DriveLetter";
		pParamTable[1].EntryContext = pDrvStr;
		pParamTable[1].DefaultType = REG_NONE;
		pParamTable[1].DefaultLength = 0;
		pParamTable[2].Name = (PWSTR)L"RootDirEntries";
		pParamTable[2].EntryContext = &RootDir;
		pParamTable[2].DefaultData = &defRootDir;
		pParamTable[3].Name = (PWSTR)L"MediaId";
		pParamTable[3].EntryContext = &MediaId;
		pParamTable[3].DefaultData = &defMediaId;
		pParamTable[4].Name = (PWSTR)L"Option";
		pParamTable[4].EntryContext = &Option;
		pParamTable[4].DefaultData = &defOption;
		pParamTable[5].Name = (PWSTR)L"Page";
		pParamTable[5].EntryContext = &Page;
		pParamTable[5].DefaultData = &defPage;
		pParamTable[6].Name = (PWSTR)L"ExtStart";
		pParamTable[6].EntryContext = &ExtStart;
		pParamTable[6].DefaultData = &defExtStart;
		bDefault = FALSE;
		/*�@���W�X�g���l�ꊇ�₢���킹�@*/
		ntStat = RtlQueryRegistryValues(RTL_REGISTRY_ABSOLUTE | RTL_REGISTRY_OPTIONAL, pRegParam->Buffer, pParamTable, NULL, NULL);
		if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
		{
			KdPrint(("Warning:RtlQueryRegistryValues failed\n"));
			bDefault = TRUE;
		}
		/*�@�₢���킹�p����������@*/
		ExFreePool(pParamTable);
	}
	if (bDefault != FALSE)	/*�@���S�ɓǂ߂Ȃ������@*/
	{
		/*�@����l���̗p�@*/
		AllocUnit = defAllocUnit;
		RootDir = defRootDir;
		MediaId = defMediaId;
		Option = defOption;
		Page = defPage;
		ExtStart = defExtStart;
	}
	#undef	REGOPTNUM
	#undef	REGOPTSIZE
	/*�@�A���P�[�V�������j�b�g�����@*/
	switch (AllocUnit)
	{
	case 1:
	case 2:
	case 4:
	case 8:
	case 16:
	case 32:
	case 64:
		pFatId->BPB.byAllocUnit = (BYTE)AllocUnit;
		break;
	}
	/*�@�f�B���N�g���G���g���ݒ�@*/
	RootDir = (RootDir + 31) & 0xffe0;	/*�@32�̔{���ɂ���@*/
	if (RootDir != 0)
	{
		pFatId->BPB.wNumDirectory = (WORD)RootDir;
	}
	/*�@���f�B�AID�Z�b�g�@*/
	if (MediaId <= 0xff)
	{
		pFatId->BPB.byMediaId = (BYTE)MediaId;
	}
	/*�@�I�v�V�����@*/
	pEramExt->uOptflag.dwOptflag |= Option;	/*�@�I�v�V��������@*/
	/*�@�I�v�V�����␳�@*/
	if (pEramExt->uOptflag.Bits.UseExtFile != 0)	/*�@�O���t�@�C���g�p�@*/
	{
		pEramExt->uOptflag.Bits.NonPaged = 0;
		pEramExt->uOptflag.Bits.External = 0;
	}
	else if (pEramExt->uOptflag.Bits.External != 0)	/*�@OS�Ǘ��O�������g�p�@*/
	{
		pEramExt->uOptflag.Bits.NonPaged = 0;
		pEramExt->uExternalStart = ExtStart;
		/*�@OS�Ǘ��O�������ő�A�h���X�̏����@*/
		GetMaxAddress(pEramExt, pRegParam);
	}
	if ((WORD)NtBuildNumber >= BUILD_NUMBER_NT50)	/*�@Windows2000�ȍ~�@*/
	{
		/*�@FAT32�L�����@*/
		pEramExt->uOptflag.Bits.EnableFat32 = 1;
	}
	if (Page > LIMIT_4GBPAGES)
	{
		Page = LIMIT_4GBPAGES;
		KdPrint(("4GB limit over, adjust %d pages\n", Page));
	}
	/*�@�y�[�W�ݒ�@*/
	if (pEramExt->uOptflag.Bits.EnableFat32 == 0)		/*�@FAT32�g��Ȃ��@*/
	{
		ulPageT = ((ULONGLONG)DISKMAXCLUSTER_16 * SECTOR * pFatId->BPB.byAllocUnit) / PAGE_SIZE_4K
;
		if ((ULONGLONG)Page > ulPageT)		/*�@FAT16�����𒴂��Ă���(�኱�]�T����)�@*/
		{
			Page = (ULONG)ulPageT;
			KdPrint(("FAT16 limit over, adjust %d pages\n", Page));
		}
	}
	else		/*�@FAT32�g���@*/
	{
		ulPageT = ((ULONGLONG)DISKMAXCLUSTER_32 * SECTOR * pFatId->BPB.byAllocUnit) / PAGE_SIZE_4K;
		if ((ULONGLONG)Page > ulPageT)		/*�@FAT32�����𒴂��Ă���@*/
		{
			Page = (ULONG)ulPageT;
			KdPrint(("FAT32 limit over, adjust %d pages\n", Page));
		}
	}
	pEramExt->uSizeTotal = Page;
	/*�@�{�����[�����x���̏����@*/
	PrepareVolumeLabel(pEramExt, pFatId, pRegParam);
	/*�@�O���t�@�C�����̏����@*/
	PrepareExtFileName(pEramExt, pFatId, pRegParam);
	KdPrint(("CheckSwitch end\n"));
}


/*�@GetMaxAddress
		���W�X�g���̎Q��(�ő�A�h���X)
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pRegParam	���W�X�g���p�X������ւ̃|�C���^
	�߂�l
		�Ȃ�
	���W�X�g���p�����[�^
		MaxAddress	�A�N�Z�X��������ő�A�h���X
*/

VOID GetMaxAddress(
	IN PERAM_EXTENSION		pEramExt,
	IN PUNICODE_STRING		pRegParam
 )
{
	/*�@���[�J���ϐ��@*/
	RTL_QUERY_REGISTRY_TABLE	ParamTable[2];
	ULONG			uMaxAdr,	defMaxAdr = 0xffffffff;
	NTSTATUS		ntStat;
	KdPrint(("GetMaxAddress start\n"));
	/*�@���W�X�g���m�F�̈揉�����@*/
	RtlZeroBytes(&(ParamTable[0]), sizeof(ParamTable));
	/*�@�ꊇ�₢���킹�̈揉����(�Ō��NULL)�@*/
	ParamTable[0].Flags = RTL_QUERY_REGISTRY_DIRECT;
	ParamTable[0].DefaultType = REG_DWORD;
	ParamTable[0].DefaultLength = sizeof(ULONG);
	ParamTable[0].Name = (PWSTR)L"MaxAddress";
	ParamTable[0].EntryContext = &uMaxAdr;
	ParamTable[0].DefaultData = &defMaxAdr;
	/*�@���W�X�g���l�₢���킹�@*/
	ntStat = RtlQueryRegistryValues(RTL_REGISTRY_ABSOLUTE | RTL_REGISTRY_OPTIONAL, pRegParam->Buffer, &(ParamTable[0]), NULL, NULL);
	if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
	{
		KdPrint(("Warning:RtlQueryRegistryValues failed\n"));
		/*�@����l���̗p�@*/
		uMaxAdr = defMaxAdr;
	}
	if (pEramExt->uExternalStart > uMaxAdr)
	{
		uMaxAdr = defMaxAdr;
	}
	pEramExt->uExternalEnd = uMaxAdr;
	KdPrint(("GetMaxAddress end\n"));
}


/*�@PrepareVolumeLabel
		���W�X�g���̎Q��(�{�����[�����x��)
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
		pRegParam	���W�X�g���p�X������ւ̃|�C���^
	�߂�l
		�Ȃ�
	���W�X�g���p�����[�^
		VolumeLabel		�{�����[�����x��
*/

VOID PrepareVolumeLabel(
	IN PERAM_EXTENSION		pEramExt,
	IN PFAT_ID				pFatId,
	IN PUNICODE_STRING		pRegParam
 )
{
	/*�@���[�J���ϐ��@*/
	static WCHAR wszDef[] = L"";
	RTL_QUERY_REGISTRY_TABLE		ParamTable[2];
	NTSTATUS		ntStat;
	UNICODE_STRING	UniVol;
	WCHAR			wszVol[12];
	KdPrint(("PrepareVolumeLabel start\n"));
	/*�@�₢���킹�p�����l�����@*/
	wszVol[0] = UNICODE_NULL;
	RtlInitUnicodeString(&UniVol, wszVol);
	UniVol.MaximumLength = sizeof(wszVol);
	/*�@���W�X�g���m�F�̈揉�����@*/
	RtlZeroBytes(&ParamTable, sizeof(ParamTable));
	/*�@�ꊇ�₢���킹�̈揉����(�Ō��NULL)�@*/
	ParamTable[0].Flags = RTL_QUERY_REGISTRY_DIRECT;
	ParamTable[0].Name = (PWSTR)L"VolumeLabel";
	ParamTable[0].EntryContext = &UniVol;
	ParamTable[0].DefaultType = REG_SZ;
	ParamTable[0].DefaultData = (LPWSTR)wszDef;
	ParamTable[0].DefaultLength = sizeof(wszDef);
	/*�@���W�X�g���l�ꊇ�₢���킹�@*/
	ntStat = RtlQueryRegistryValues(RTL_REGISTRY_ABSOLUTE | RTL_REGISTRY_OPTIONAL, pRegParam->Buffer, &(ParamTable[0]), NULL, NULL);
	if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
	{
		KdPrint(("Warning:RtlQueryRegistryValues failed, 0x%x\n", ntStat));
	}
	/*�@�{�����[�����x���@*/
	RtlFillMemory(pFatId->bsLabel, sizeof(pFatId->bsLabel), ' ');
	if ((UniVol.Length == 0)||						/*�@�w�薳���@*/
		(CheckVolumeLabel(pEramExt, pFatId, &UniVol) == FALSE))		/*�@�w�蕶���񖳌��@*/
	{
#pragma warning(disable : 4127)
		ASSERT((sizeof(pFatId->bsLabel)+1) == sizeof(VOLUME_LABEL_LOCALDISK));
		ASSERT((sizeof(pFatId->bsLabel)+1) == sizeof(VOLUME_LABEL_RAMDISK));
#pragma warning(default : 4127)
		RtlCopyBytes(pFatId->bsLabel, (PSTR)((pEramExt->uOptflag.Bits.Swapable != 0) ? VOLUME_LABEL_LOCALDISK : VOLUME_LABEL_RAMDISK), sizeof(pFatId->bsLabel));
	}
	KdPrint(("PrepareVolumeLabel end, Volume label \"%s\"\n", pFatId->bsLabel));
}


/*�@CheckVolumeLabel
		�{�����[�����x���̐������m�F�Ə���
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
		pUniVol		���W�X�g������ǂ񂾃{�����[�����x��������ւ̃|�C���^
	�߂�l
		����		TRUE:�����ς�
*/

BOOLEAN CheckVolumeLabel(
	IN PERAM_EXTENSION		pEramExt,
	IN PFAT_ID				pFatId,
	IN PUNICODE_STRING		pUniVol
 )
{
	/*�@���[�J���ϐ��@*/
	static CHAR cBadChars[] = "*?/|.,;:+=[]()&^<>\"";
	ANSI_STRING		AnsiVol;
	DWORD loopi, loopj;
	/*�@�s�����������@*/
	for (loopi=0; loopi<(pUniVol->Length / sizeof(WCHAR)); loopi++)
	{
		if (HIBYTE(pUniVol->Buffer[loopi]) == 0)
		{
			if (LOBYTE(pUniVol->Buffer[loopi]) < ' ')
			{
				KdPrint(("Bad char 0x%x detected, index %d\n", LOBYTE(pUniVol->Buffer[loopi]), loopi));
				return FALSE;
			}
			for (loopj=0; loopj<(sizeof(cBadChars)-1); loopj++)
			{
				if (LOBYTE(pUniVol->Buffer[loopi]) == cBadChars[loopj])
				{
					KdPrint(("Bad char \"%c\" detected, index %d\n", cBadChars[loopj], loopi));
					return FALSE;
				}
			}
		}
	}
	/*�@ANSI�����񉻁@*/
	if (RtlUnicodeStringToAnsiString(&AnsiVol, pUniVol, TRUE) != STATUS_SUCCESS)
	{
		KdPrint(("RtlUnicodeStringToAnsiString failed\n"));
		return FALSE;
	}
	if (AnsiVol.Length == 0)		/*�@���̖����@*/
	{
		KdPrint(("Ansi string 0 byte\n"));
		RtlFreeAnsiString(&AnsiVol);
		return FALSE;
	}
	/*�@�����@*/
	RtlCopyBytes(pFatId->bsLabel, AnsiVol.Buffer, (AnsiVol.Length > sizeof(pFatId->bsLabel)) ? sizeof(pFatId->bsLabel) : AnsiVol.Length);
	RtlFreeAnsiString(&AnsiVol);
	KdPrint(("CheckVolumeLabel end, Volume label \"%s\"\n", pFatId->bsLabel));
	return TRUE;
}


/*�@PrepareExtFileName
		���W�X�g���̎Q��(�O���t�@�C����)
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
		pRegParam	���W�X�g���p�X������ւ̃|�C���^
	�߂�l
		�Ȃ�
	���W�X�g���p�����[�^
		ExtFileName		�O���t�@�C����
*/

VOID PrepareExtFileName(
	IN PERAM_EXTENSION		pEramExt,
	IN PFAT_ID				pFatId,
	IN PUNICODE_STRING		pRegParam
 )
{
	/*�@���[�J���ϐ��@*/
	static WCHAR wszDef[] = L"";
	static WCHAR wszExtStub[] = L"\\??\\";
	static WCHAR wszExtPath[] = ERAMEXTFILEPATH;
	RTL_QUERY_REGISTRY_TABLE		ParamTable[2];
	NTSTATUS		ntStat;
	UNICODE_STRING	UniExtFile;
	KdPrint(("PrepareExtFileName start\n"));
	/*�@�₢���킹�p�����l�����@*/
	pFatId->wszExtFileMain[0] = UNICODE_NULL;
	RtlInitUnicodeString(&UniExtFile, pFatId->wszExtFileMain);
	UniExtFile.MaximumLength = sizeof(pFatId->wszExtFileMain);
	/*�@���W�X�g���m�F�̈揉�����@*/
	RtlZeroBytes(&ParamTable, sizeof(ParamTable));
	/*�@�ꊇ�₢���킹�̈揉����(�Ō��NULL)�@*/
	ParamTable[0].Flags = RTL_QUERY_REGISTRY_DIRECT;
	ParamTable[0].Name = (PWSTR)L"ExtFileName";
	ParamTable[0].EntryContext = &UniExtFile;
	ParamTable[0].DefaultType = REG_SZ;
	ParamTable[0].DefaultData = (LPWSTR)wszDef;
	ParamTable[0].DefaultLength = sizeof(wszDef);
	/*�@���W�X�g���l�ꊇ�₢���킹�@*/
	ntStat = RtlQueryRegistryValues(RTL_REGISTRY_ABSOLUTE | RTL_REGISTRY_OPTIONAL, pRegParam->Buffer, &(ParamTable[0]), NULL, NULL);
	if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
	{
		KdPrint(("Warning:RtlQueryRegistryValues failed\n"));
	}
	/*�@�O���t�@�C�����@*/
#pragma warning(disable : 4127)
	ASSERT(sizeof(pFatId->wszExtFile) == (sizeof(wszExtStub) - sizeof(WCHAR)));
#pragma warning(default : 4127)
	RtlCopyBytes(pFatId->wszExtFile, wszExtStub, sizeof(pFatId->wszExtFile));
	if (UniExtFile.Length == 0)			/*�@�O���t�@�C�����w�薳���@*/
	{
		RtlCopyBytes(pFatId->wszExtFileMain, wszExtPath, sizeof(wszExtPath));
	}
	KdPrint(("PrepareExtFileName end, External file \"%ls\"\n", pFatId->wszExtFile));
}


/*�@EramFormatFat
		ERAM������
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
	�߂�l
		����
*/

BOOLEAN EramFormatFat(
	IN PERAM_EXTENSION	pEramExt,
	IN PFAT_ID			pFatId
 )
{
	KdPrint(("EramFormatFat start\n"));
	/*�@FAT���Z�b�g�A�b�v�@*/
	EramSetup(pEramExt, pFatId);
	/*�@���[�`���̓��I�z�u�@*/
	EramLocate(pEramExt);
	/*�@ERAM�t�H�[�}�b�g�@*/
	if (EramFormat(pEramExt, pFatId) == FALSE)
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "EramFormat");
		return FALSE;
	}
	KdPrint(("EramFormatFat end\n"));
	return TRUE;
}


/*�@EramSetup
		�f�B�X�N���Z�b�g�A�b�v
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID EramSetup(
	IN PERAM_EXTENSION	pEramExt,
	IN PFAT_ID			pFatId
 )
{
	/*�@���[�J���ϐ��@*/
	UINT	AllocLog2;
	DWORD	eax, esi, edi, ebx, edx, dwFatSectorCount, dwFatEntries;
	KdPrint(("EramSetup start\n"));
	/*�@log2(�۹���ݻ���)�v�Z�@*/
	switch (pFatId->BPB.byAllocUnit)
	{
	case 2:
		AllocLog2 = 1;
		break;
	case 4:
		AllocLog2 = 2;
		break;
	case 8:
		AllocLog2 = 3;
		break;
	case 16:
		AllocLog2 = 4;
		break;
	case 32:
		AllocLog2 = 5;
		break;
	case 64:
		AllocLog2 = 6;
		break;
	default:
		AllocLog2 = 0;
	}
	edi = pEramExt->uSizeTotal << PAGE_SEC_LOG2;
	pEramExt->uAllSector = edi;						/*�@�S������@*/
	pFatId->BPB.wNumAllSector = (WORD)edi;			/*�@�S������@*/
	if (edi >= 0x10000)								/*�@over32MB�@*/
	{
		pFatId->BPB.wNumAllSector = 0;
		pFatId->BPB_ext.bsHugeSectors = edi;			/*�@�S������@*/
		if (pEramExt->uOptflag.Bits.EnableFat32 != 0)	/*�@FAT32�L���@*/
		{
			/*�@BootSector��FsInfo�Z�N�^�������ė\��G���g��2��������@*/
			dwFatEntries = ((edi - RESV_SECTOR_FAT32) >> AllocLog2) + 2;
			if (dwFatEntries > DISKMAXCLUSTER_16)		/*�@�N���X�^����@*/
			{
				dwFatSectorCount = (dwFatEntries * 4 + (SECTOR - 1)) / SECTOR;
				dwFatEntries -= dwFatSectorCount;
				if (dwFatEntries > DISKMAXCLUSTER_16)		/*�@�N���X�^����@*/
				{
					/*�@FAT32�g�p��ݒ�@*/
					pEramExt->FAT_size = PARTITION_FAT32;
					pFatId->BPB.wNumDirectory = 0;
					pFatId->BPB_fat32.dwNumFatSector32 = dwFatSectorCount;
					pFatId->BPB.wNumResvSector = RESV_SECTOR_FAT32;	/*�@�\��Z�N�^��(=BootSector+FsInfo)�@*/
					KdPrint(("EramSetup end(FAT32)\n"));
					return;
				}
			}
		}
	}
	esi = pFatId->BPB.wNumDirectory;	/*�@�ިڸ�ش��ؐ��@*/
	esi >>= (SECTOR_LOG2 - 5);			/*�@1�����16����cSI=�ިڸ�ؾ�����@*/
	if ((esi == 0)||					/*�@�f�B���N�g���w�薳���@*/
		((edi >> 1) <= esi))			/*�@�f�B���N�g���w�肪�S�Z�N�^�̔���������@*/
	{
		pFatId->BPB.wNumDirectory = 128;						/*�@�����I�Ɋ���l�ɕύX�@*/
		esi = pFatId->BPB.wNumDirectory >> (SECTOR_LOG2 - 5);	/*�@1�����16����cSI=�ިڸ�ؾ�����@*/
	}
	edi -= (esi + 1);					/*�@di = �S����� - �ިڸ�ؾ���� - �\������@*/
	edx = edi;							/*�@���p�\������@*/
	edi >>= AllocLog2;					/*�@�T�Z�׽��� = di / �׽�����̾���@*/
	edi++;								/*�@�T�Z�׽���+1�@*/
	pEramExt->FAT_size = PARTITION_FAT_12;
	/*�@AllocLog2 = log2 �۹���ݥ����
		dx = ���p�\�����
		si = ٰ��ިڸ�ؗp�̾����
		di = �T�Z�׽��� + 1
	*/
	do
	{
		edi--;					/*�@�T�Z�׽���-1�@*/
		if (edi > DISKMAXCLUSTER_12)	/*�@0FF7h�ȏ�Ȃ�16bit FAT�@*/
		{
			pEramExt->FAT_size = PARTITION_FAT_16;
			eax = edi;
			eax <<= 1;			/*�@eax=FAT�޲Đ�(2�{)�@*/
			eax += (SECTOR + 3);
			eax >>= SECTOR_LOG2;/*�@eax=FAT ������@*/
			pFatId->BPB.wNumFatSector = (WORD)eax;
		}
		else	/*�@12bit FAT�@*/
		{
			pEramExt->FAT_size = PARTITION_FAT_12;
			eax = edi;
			eax *= 3;
			eax >>= 1;			/*�@ax=FAT�޲Đ�(1.5�{)�@*/
			eax += (SECTOR + 2);
			eax >>= SECTOR_LOG2;	/*�@ax=FAT ������@*/
			pFatId->BPB.wNumFatSector = (WORD)eax;
		}
		ebx = edi;				/*�@bx = �ް��������@*/
		ebx <<= AllocLog2;
		ebx += eax;				/*�@+ FAT  ������@*/
	} while (ebx > edx);
	/*�@12bit FAT�ł̎g�p�̈�̒���
		0FF5h:FD ��16bit FAT�ƌ�F
	*/
	if ((pEramExt->FAT_size == PARTITION_FAT_12)&&
		(edi > (DISKMAXCLUSTER_12 - 3)))
	{
		edi -= (DISKMAXCLUSTER_12 - 3);
		edi <<= AllocLog2;
		edi <<= (SECTOR_LOG2 - 5);
#pragma warning(disable : 4244)
		pFatId->BPB.wNumDirectory += (WORD)edi;	/*�@ٰ��ިڸ�ؐ��Œ����@*/
#pragma warning(default : 4244)
	}
	/*�@16bit FAT�ł̎g�p�̈�̒���
		0FFF6h:FAT32
	*/
	if ((pEramExt->FAT_size == PARTITION_FAT_16)&&
		(edi > DISKMAXCLUSTER_16 - 1))
	{
		edi -= DISKMAXCLUSTER_16 - 1;
		edi <<= AllocLog2;
		edi <<= (SECTOR_LOG2 - 5);
#pragma warning(disable : 4244)
		pFatId->BPB.wNumDirectory += (WORD)edi;	/*�@ٰ��ިڸ�ؐ��Œ����@*/
#pragma warning(default : 4244)
	}
	edx -= ebx;			/*�@bx=���g�p������@*/
	if (edx != 0)		/*�@�[�������dir�ɂ܂킷�@*/
	{
		edx <<= (SECTOR_LOG2 - 5);
#pragma warning(disable : 4244)
		pFatId->BPB.wNumDirectory += (WORD)edx;
#pragma warning(default : 4244)
	}
	if ((pEramExt->FAT_size == PARTITION_FAT_16)&&
		(pFatId->BPB.wNumAllSector == 0))	/*�@FAT16 over 32MB�@*/
	{
		pEramExt->FAT_size = PARTITION_HUGE;
	}
	KdPrint(("EramSetup end(FAT12,16)\n"));
}


/*�@EramLocate
		���[�`���̓��I�z�u
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
	�߂�l
		�Ȃ�
*/

VOID EramLocate(
	IN PERAM_EXTENSION	pEramExt
 )
{
	KdPrint(("EramLocate start\n"));
	if (pEramExt->uOptflag.Bits.External != 0)	/*�@OS�Ǘ��O�������g�p�@*/
	{
		pEramExt->EramRead = (ERAM_READ)ExtRead1;
		pEramExt->EramWrite = (ERAM_WRITE)ExtWrite1;
		pEramExt->EramNext = (ERAM_NEXT)ExtNext1;
		pEramExt->EramUnmap = (ERAM_UNMAP)ExtUnmap;
	}
	else if (pEramExt->uOptflag.Bits.UseExtFile != 0)	/*�@�t�@�C���g�p�@*/
	{
		pEramExt->EramRead = (ERAM_READ)ExtFilePendingRw;
		pEramExt->EramWrite = (ERAM_WRITE)ExtFilePendingRw;
		pEramExt->EramNext = (ERAM_NEXT)ExtFileNext1;
		pEramExt->EramUnmap = (ERAM_UNMAP)ExtFileUnmap;
	}
	else		/*�@�ʏ�@*/
	{
		pEramExt->EramRead = (ERAM_READ)ReadPool;
		pEramExt->EramWrite = (ERAM_WRITE)WritePool;
	}
	KdPrint(("EramLocate end\n"));
}


/*�@EramFormat
		�t�H�[�}�b�g
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
	�߂�l
		����
*/

BOOLEAN EramFormat(
	IN PERAM_EXTENSION	pEramExt,
	IN PFAT_ID			pFatId
 )
{
	KdPrint(("EramFormat start\n"));
	/*�@�Ǘ��̈�̏������@*/
	if (EramClearInfo(pEramExt, pFatId) == FALSE)
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "EramClearInfo");
		return FALSE;
	}
	/*�@FAT�������@*/
	if (EramMakeFAT(pEramExt, pFatId) == FALSE)
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "EramMakeFAT");
		return FALSE;
	}
	/*�@�{�����[�����x�����Z�b�g�@*/
	if (EramSetLabel(pEramExt, pFatId) == FALSE)
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "EramSetLabel");
		return FALSE;
	}
	KdPrint(("EramFormat end\n"));
	return TRUE;
}


/*�@EramClearInfo
		�̈�N���A
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
	�߂�l
		����
*/

BOOLEAN EramClearInfo(
	IN PERAM_EXTENSION	pEramExt,
	IN PFAT_ID			pFatId
 )
{
	/*�@���[�J���ϐ��@*/
	ULONG uSize;
	/*�@�Ǘ��̈�T�C�Y�v�Z�@*/
	uSize = CalcEramInfoPage(pEramExt, pFatId);
	if (pEramExt->uOptflag.Bits.External != 0)	/*�@OS�Ǘ��O�������@*/
	{
		/*�@OS�Ǘ��O�������������@*/
		if (ExtClear(pEramExt, uSize) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ExtClear");
			return FALSE;
		}
		return TRUE;
	}
	if (pEramExt->uOptflag.Bits.UseExtFile != 0)	/*�@�O���t�@�C���g�p�@*/
	{
		/*�@�t�@�C���������@*/
		if (ExtFileClear(pEramExt, uSize) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ExtFileClear");
			return FALSE;
		}
		return TRUE;
	}
	/*�@OS�Ǘ��������������@*/
	RtlZeroBytes(pEramExt->pPageBase, uSize);
	return TRUE;
}


/*�@ExtClear
		OS�Ǘ��O������������
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		uSize		�Ǘ����̈�̃o�C�g��
	�߂�l
		����
*/

BOOLEAN ExtClear(
	IN PERAM_EXTENSION	pEramExt,
	IN ULONG			uSize
 )
{
	/*�@���[�J���ϐ��@*/
	ULONG loopi;
	KdPrint(("ExtClear start\n"));
	ASSERT(pEramExt->uExternalStart != 0);
	ASSERT(pEramExt->uExternalEnd != 0);
	for (loopi=0; loopi<uSize; loopi+=EXT_PAGE_SIZE)
	{
		if ((pEramExt->uExternalStart + loopi) >= pEramExt->uExternalEnd)	/*�@���������𒴂��Ă���@*/
		{
			KdPrint(("Warning:Address limited\n"));
			break;
		}
		/*�@�}�b�v�@*/
		if (ExtMap(pEramExt, loopi) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ExtMap");
			return FALSE;
		}
		//KdPrint(("loop 0x%x, phys 0x%X\n", loopi, (pEramExt->uExternalStart + loopi)));
		/*�@0�N���A�@*/
		RtlZeroBytes(pEramExt->pExtPage, ((uSize - loopi) > EXT_PAGE_SIZE ? EXT_PAGE_SIZE : (uSize - loopi)));
	}
	/*�@�A���}�b�v�@*/
	ExtUnmap(pEramExt);
	KdPrint(("ExtClear end\n"));
	return TRUE;
}


/*�@ExtFileClear
		�t�@�C��������
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		uSize		�Ǘ����̈�̃o�C�g��
	�߂�l
		����
*/

BOOLEAN ExtFileClear(
	IN PERAM_EXTENSION	pEramExt,
	IN ULONG			uSize
 )
{
	/*�@���[�J���ϐ��@*/
	ULONG loopi;
	KdPrint(("ExtFileClear start\n"));
	for (loopi=0; loopi<uSize; loopi+=EXT_PAGE_SIZE)
	{
		/*�@�}�b�v�@*/
		if (ExtFileMap(pEramExt, loopi) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ExtFileMap");
			return FALSE;
		}
		//KdPrint(("loop 0x%x, phys 0x%X\n", loopi, (pEramExt->uExternalStart + loopi)));
		/*�@0�N���A�@*/
		RtlZeroBytes(pEramExt->pExtPage, ((uSize - loopi) > EXT_PAGE_SIZE ? EXT_PAGE_SIZE : (uSize - loopi)));
	}
	/*�@�A���}�b�v�@*/
	ExtFileUnmap(pEramExt);
	KdPrint(("ExtFileClear end\n"));
	return TRUE;
}


/*�@CalcEramInfoPage
		�Ǘ��̈�T�C�Y�v�Z
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
	�߂�l
		����
*/

DWORD CalcEramInfoPage(
	IN PERAM_EXTENSION	pEramExt,
	IN PFAT_ID			pFatId
 )
{
	/*�@���[�J���ϐ��@*/
	DWORD dwBytes, dwPage, dwTmp;
	KdPrint(("CalcEramInfoPage start\n"));
	if (pEramExt->FAT_size == PARTITION_FAT32)	/*�@FAT32�@*/
	{
		dwPage = pFatId->BPB_fat32.dwNumFatSector32 + pFatId->BPB.wNumResvSector + pFatId->BPB_fat32.dwRootCluster * (pFatId->BPB.byAllocUnit);
	}
	else		/*�@FAT12/16�@*/
	{
		dwPage = pFatId->BPB.wNumFatSector + pFatId->BPB_fat32.dwNumFatSector32;	/*�@FAT�Z�N�^���@*/
		dwTmp = pFatId->BPB.wNumDirectory;	/*�@�f�B���N�g���G���g�����@*/
		dwTmp >>= (SECTOR_LOG2 - 5);			/*�@�f�B���N�g���Z�N�^���@*/
		dwPage += dwTmp;						/*�@FAT�{�f�B���N�g���@*/
		dwPage += pFatId->BPB.wNumResvSector;	/*�@�\��Z�N�^���@*/
	}
	if (pEramExt->uOptflag.Bits.MakeTempDir != 0)	/*�@TEMP�f�B���N�g���쐬�@*/
	{
		/*�@1�N���X�^�����₷�@*/
		dwPage += pFatId->BPB.byAllocUnit;
	}
	dwPage += (PAGE_SECTOR - 1);			/*�@�؂�グ�p�@*/
	dwPage >>= PAGE_SEC_LOG2;				/*�@�y�[�W���@*/
	dwBytes = (dwPage << PAGE_SIZE_LOG2);	/*�@�������o�C�g���@*/
	if (dwBytes > (pEramExt->uSizeTotal * PAGE_SIZE_4K))
	{
		dwBytes = pEramExt->uSizeTotal * PAGE_SIZE_4K;
	}
	KdPrint(("CalcEramInfoPage end, 0x%x bytes\n", dwBytes));
	return dwBytes;
}


/*�@EramMakeFAT
		FAT�쐬
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
	�߂�l
		����
*/

BOOLEAN EramMakeFAT(
	IN PERAM_EXTENSION	pEramExt,
	IN PFAT_ID			pFatId
 )
{
	/*�@���[�J���ϐ��@*/
	WORD wVal;
	PBYTE pDisk;
	PDWORD pdwFatSector;
	PBOOTSECTOR_FAT16 pBootFat16;
	PBOOTSECTOR_FAT32 pBootFat32;
	PFSINFO_SECTOR pFsInfoSector;
	LARGE_INTEGER SystemTime, LocalTime;
	DWORD eax, ebx;
	KdPrint(("EramMakeFAT start\n"));
	/*�@���t�A�������擾�@*/
	KeQuerySystemTime(&SystemTime);						/*�@�V�X�e�������擾�@*/
	ExSystemTimeToLocalTime(&SystemTime, &LocalTime);	/*�@���[�J�������ɕϊ��@*/
	RtlTimeToTimeFields(&LocalTime, &(pFatId->TimeInfo));	/*�@�\���̂ɕϊ��@*/
	if ((pFatId->TimeInfo.Year < 1980)||(pFatId->TimeInfo.Year > 2079))	/*�@�N��DOS�͈̔͂��z�����@*/
	{
		/*�@2004�N���Z�b�g�@*/
		pFatId->TimeInfo.Year = 2004;
	}
	/*�@�{�����[���V���A���ԍ��������@*/
	wVal = pFatId->TimeInfo.Year;
	pFatId->BPB_ext2.bsVolumeID = (wVal / 1000) << 28;
	wVal %= 1000;
	pFatId->BPB_ext2.bsVolumeID |= ((wVal / 100) << 24);
	wVal %= 100;
	pFatId->BPB_ext2.bsVolumeID |= ((wVal / 10) << 20);
	pFatId->BPB_ext2.bsVolumeID |= ((wVal % 10) << 16);
	pFatId->BPB_ext2.bsVolumeID |= ((pFatId->TimeInfo.Month / 10) << 12);
	pFatId->BPB_ext2.bsVolumeID |= ((pFatId->TimeInfo.Month % 10) << 8);
	pFatId->BPB_ext2.bsVolumeID |= ((pFatId->TimeInfo.Day / 10) << 4);
	pFatId->BPB_ext2.bsVolumeID |= (pFatId->TimeInfo.Day % 10);
	pDisk = pEramExt->pPageBase;
	if ((pEramExt->uOptflag.Bits.External != 0)||		/*�@OS�Ǘ��O�������g�p�@*/
		(pEramExt->uOptflag.Bits.UseExtFile != 0))		/*�@�O���t�@�C���g�p�@*/
	{
		/*�@�u�[�g�Z�N�^���蓖�ā@*/
		ebx = 0;
		ASSERT((pEramExt->EramNext) != NULL);
		if ((*(pEramExt->EramNext))(pEramExt, &eax, &ebx) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "EramNext");
			return FALSE;
		}
		pDisk = (PBYTE)((ULONG)(pEramExt->pExtPage + eax));
	}
	/*�@�u�[�g�Z�N�^���ʕ��̏������݁@*/
	pBootFat16 = (PBOOTSECTOR_FAT16)pDisk;
	pBootFat16->bsJump[0] = 0xeb;
	pBootFat16->bsJump[1] = 0xfe;
	pBootFat16->bsJump[2] = 0x90;
	RtlCopyBytes(pBootFat16->bsOemName, "ERAM    ", sizeof(pBootFat16->bsOemName));
	RtlCopyBytes(&(pBootFat16->BPB), &(pFatId->BPB), sizeof(pBootFat16->BPB));
	RtlCopyBytes(&(pBootFat16->BPB_ext), &(pFatId->BPB_ext), sizeof(pBootFat16->BPB_ext));
	RtlCopyBytes(pBootFat16->szMsg, FATID_MSG, sizeof(FATID_MSG));
	if (pEramExt->FAT_size != PARTITION_FAT32)	/*�@FAT12,16�@*/
	{
		/*�@�u�[�g�Z�N�^(FAT12,16)�̏������݁@*/
		RtlCopyBytes(&(pBootFat16->BPB_ext2), &(pFatId->BPB_ext2), sizeof(pBootFat16->BPB_ext2));
	}
	else										/*�@FAT32�@*/
	{
		/*�@�u�[�g�Z�N�^(FAT32)�̏������݁@*/
		pBootFat32 = (PBOOTSECTOR_FAT32)pDisk;
		RtlCopyBytes(&(pBootFat32->BPB_fat32), &(pFatId->BPB_fat32), sizeof(pBootFat32->BPB_fat32));
		RtlCopyBytes(&(pBootFat32->BPB_ext2), &(pFatId->BPB_ext2), sizeof(pBootFat32->BPB_ext2));
		/*�@FSINFO�Z�N�^�̏������݁@*/
		pFsInfoSector = (PFSINFO_SECTOR)((ULONG)pBootFat32 + pBootFat32->BPB_fat32.wFsInfoSector * SECTOR);
		pFsInfoSector->FSInfo_Sig = 0x41615252;				/*�@RRaA�@*/
		pFsInfoSector->FsInfo.bfFSInf_Sig = 0x61417272;		/*�@rrAa�@*/
		pFsInfoSector->FsInfo.bfFSInf_free_clus_cnt = 0xffffffff;
		pFsInfoSector->FsInfo.bfFSInf_next_free_clus = 2;
		pFsInfoSector->bsSig2[0] = 0x55;
		pFsInfoSector->bsSig2[1] = 0xaa;
		if ((pBootFat32->BPB_fat32.wBackupBootSector != 0xffff)&&	/*�@�o�b�N�A�b�v�u�[�g�Z�N�^���݁@*/
			(pBootFat32->BPB.wNumResvSector > (pBootFat32->BPB_fat32.wBackupBootSector + pBootFat32->BPB_fat32.wFsInfoSector))&&
			((pBootFat32->BPB_fat32.wBackupBootSector + pBootFat32->BPB_fat32.wFsInfoSector) < (EXT_PAGE_SIZE / SECTOR)))
		{
			/*�@�u�[�g�Z�N�^���o�b�N�A�b�v�@*/
			RtlCopyBytes((PBYTE)((ULONG)pBootFat32 + pBootFat32->BPB_fat32.wBackupBootSector * SECTOR), pBootFat32, sizeof(*pBootFat32));
			/*�@FSINFO�Z�N�^���o�b�N�A�b�v�@*/
			RtlCopyBytes((PBYTE)((ULONG)pFsInfoSector + pBootFat32->BPB_fat32.wBackupBootSector * SECTOR), pFsInfoSector, sizeof(*pFsInfoSector));
		}
	}
	/*�@FAT�Z�N�^�̏������݁@*/
	pdwFatSector = (PDWORD)((ULONG)pBootFat16 + pBootFat16->BPB.wNumResvSector * SECTOR);
	pdwFatSector[0] = 0xffffff00 + pFatId->BPB.byMediaId;
	if (pEramExt->FAT_size == PARTITION_FAT_12)	/*�@FAT12�@*/
	{
		if (pEramExt->uOptflag.Bits.MakeTempDir != 0)		/*�@TEMP�쐬�@*/
		{
			/*�@�N���X�^2���g�p���ɂ���(�v36bit)�@*/
			((PBYTE)pdwFatSector)[4] = 0xf;
		}
		else
		{
			/*�@24bit�ɍi��@*/
			((PBYTE)pdwFatSector)[3] = 0;
		}
	}
	else if (pEramExt->FAT_size == PARTITION_FAT32)	/*�@FAT32�@*/
	{
		pdwFatSector[1] = 0xffffffff;
		/*�@���[�g�f�B���N�g�����ݒ�@*/
		pdwFatSector[pFatId->BPB_fat32.dwRootCluster] = 0x0fffffff;
		if (pEramExt->uOptflag.Bits.MakeTempDir != 0)		/*�@TEMP�쐬�@*/
		{
			/*�@���[�g�f�B���N�g���̎��̃N���X�^���g�p���ɂ���(�v96bit)�@*/
			pdwFatSector[pFatId->BPB_fat32.dwRootCluster + 1] = 0x0fffffff;
		}
	}
	else if (pEramExt->uOptflag.Bits.MakeTempDir != 0)		/*�@FAT16��TEMP�쐬�@*/
	{
		/*�@�N���X�^2���g�p���ɂ���(�v48bit)�@*/
		pdwFatSector[1] = 0xffff;
	}
	if (pEramExt->uOptflag.Bits.External != 0)	/*�@OS�Ǘ��O�������g�p�@*/
	{
		/*�@�A���}�b�v�@*/
		ExtUnmap(pEramExt);
	}
	else if (pEramExt->uOptflag.Bits.UseExtFile != 0)	/*�@�O���t�@�C���g�p�@*/
	{
		/*�@�A���}�b�v�@*/
		ExtFileUnmap(pEramExt);
	}
	KdPrint(("EramMakeFAT end\n"));
	return TRUE;
}


/*�@EramSetLabel
		�{�����[�����x���̃Z�b�g
	����
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pFatId		FAT-ID�\���̂ւ̃|�C���^
	�߂�l
		����
*/

BOOLEAN EramSetLabel(
	IN PERAM_EXTENSION	pEramExt,
	IN PFAT_ID			pFatId
 )
{
	/*�@���[�J���ϐ��@*/
	vol_label VOL_L;
	dir_init DirInit;
	DWORD eax, dwDirSector, dwTempSector;
	KdPrint(("EramSetLabel start\n"));
	/*�@�������@*/
	RtlZeroBytes(&VOL_L, sizeof(VOL_L));
	RtlZeroBytes(&DirInit, sizeof(DirInit));
	/*�@�{�����[�����x���������@*/
	RtlCopyBytes(VOL_L.vol.sName, pFatId->bsLabel, sizeof(VOL_L.vol.sName));
	KdPrint(("Volume label \"%s\"\n", VOL_L.vol.sName));
	/*�@������ݒ�@*/
	VOL_L.vol.uAttr.Bits.byVol = 1;
	VOL_L.vol.uAttr.Bits.byA = 1;
	/*�@���t�A������ݒ�@*/
	VOL_L.vol.wUpdMinute |= (pFatId->TimeInfo.Second >> 1);				/*�@�b��1�r�b�g������@*/
	VOL_L.vol.wUpdMinute |= (pFatId->TimeInfo.Minute << 5);				/*�@���̃Z�b�g�@*/
	VOL_L.vol.wUpdMinute |= (pFatId->TimeInfo.Hour << (5+6));			/*�@���̃Z�b�g�@*/
	VOL_L.vol.wUpdDate |= pFatId->TimeInfo.Day;
	VOL_L.vol.wUpdDate |= (pFatId->TimeInfo.Month << 5);
	VOL_L.vol.wUpdDate |= ((pFatId->TimeInfo.Year - 1980) << (5+4));
	/*�@�f�B���N�g���Z�N�^�ʒu���擾�@*/
	dwDirSector = pFatId->BPB.wNumFatSector + pFatId->BPB.wNumResvSector;
	if (pEramExt->FAT_size == PARTITION_FAT32)		/*�@FAT32�@*/
	{
		dwDirSector = pFatId->BPB_fat32.dwNumFatSector32 + pFatId->BPB.wNumResvSector + (pFatId->BPB_fat32.dwRootCluster - 2) * (pFatId->BPB.byAllocUnit);
	}
	if (pEramExt->uOptflag.Bits.MakeTempDir != 0)		/*�@TEMP�f�B���N�g���쐬�@*/
	{
		/*�@�f�B���N�g���������@*/
		RtlCopyBytes(VOL_L.temp.sName, TEMPDIR_NAME, sizeof(VOL_L.temp.sName));
		/*�@������ݒ�@*/
		VOL_L.temp.uAttr.Bits.byDir = 1;
		VOL_L.temp.uAttr.Bits.byA = 1;
		/*�@���t�A������ݒ�@*/
		VOL_L.temp.wUpdMinute = VOL_L.vol.wUpdMinute;
		VOL_L.temp.wUpdDate = VOL_L.vol.wUpdDate;
		if (pEramExt->FAT_size == PARTITION_FAT32)		/*�@FAT32�@*/
		{
			/*�@�擪�N���X�^�ԍ���ݒ�@*/
			VOL_L.temp.wCluster = (WORD)(pFatId->BPB_fat32.dwRootCluster + 1);
			/*�@�擪�Z�N�^�����v�Z�@*/
			dwTempSector = pFatId->BPB_fat32.dwNumFatSector32 + pFatId->BPB.wNumResvSector + (VOL_L.temp.wCluster - 2) * (pFatId->BPB.byAllocUnit);
		}
		else
		{
			/*�@�擪�N���X�^�ԍ���ݒ�@*/
			VOL_L.temp.wCluster = 2;
			/*�@�擪�Z�N�^�����v�Z�@*/
			dwTempSector = dwDirSector + (pFatId->BPB.wNumDirectory >> (SECTOR_LOG2 - 5));
		}
		/*�@�f�B���N�g���������@*/
		RtlCopyBytes(DirInit.own.sName, OWNDIR_NAME, sizeof(DirInit.own.sName));
		RtlCopyBytes(DirInit.parent.sName, PARENTDIR_NAME, sizeof(DirInit.parent.sName));
		/*�@������ݒ�@*/
		DirInit.own.uAttr.byAttr = VOL_L.temp.uAttr.byAttr;
		DirInit.parent.uAttr.byAttr = VOL_L.temp.uAttr.byAttr;
		/*�@���t�A������ݒ�@*/
		DirInit.own.wUpdMinute = VOL_L.vol.wUpdMinute;
		DirInit.own.wUpdDate = VOL_L.vol.wUpdDate;
		DirInit.parent.wUpdMinute = VOL_L.vol.wUpdMinute;
		DirInit.parent.wUpdDate = VOL_L.vol.wUpdDate;
		/*�@�擪�N���X�^�ԍ���ݒ�@*/
		DirInit.own.wCluster = VOL_L.temp.wCluster;
	}
	if ((pEramExt->uOptflag.Bits.External != 0)||		/*�@OS�Ǘ��O�������g�p�@*/
		(pEramExt->uOptflag.Bits.UseExtFile != 0))		/*�@�O���t�@�C���g�p�@*/
	{
		/*�@�f�B���N�g���Z�N�^�����蓖�ā@*/
		ASSERT((pEramExt->EramNext) != NULL);
		if ((*(pEramExt->EramNext))(pEramExt, &eax, &dwDirSector) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "EramNext");
			return FALSE;
		}
		/*�@�{�����[�����x���������݁@*/
		RtlCopyBytes((LPBYTE)((ULONG)(pEramExt->pExtPage) + eax), &VOL_L, sizeof(VOL_L));
		if (pEramExt->uOptflag.Bits.MakeTempDir != 0)		/*�@TEMP�f�B���N�g���쐬�@*/
		{
			/*�@TEMP�f�B���N�g���Z�N�^�����蓖�ā@*/
			if ((*(pEramExt->EramNext))(pEramExt, &eax, &dwTempSector) == FALSE)
			{
				EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "EramNext");
				return FALSE;
			}
			/*�@�f�B���N�g���������݁@*/
			RtlCopyBytes((LPBYTE)((ULONG)(pEramExt->pExtPage) + eax), &DirInit, sizeof(DirInit));
		}
		/*�@�A���}�b�v�@*/
		ASSERT((pEramExt->EramUnmap) != NULL);
		(*(pEramExt->EramUnmap))(pEramExt);
	}
	else
	{
		/*�@�f�B���N�g���Z�N�^�Ƀ{�����[�����x���������݁@*/
		RtlCopyBytes((LPBYTE)((ULONG)(pEramExt->pPageBase) + (dwDirSector << SECTOR_LOG2)), &VOL_L, sizeof(VOL_L));
		if (pEramExt->uOptflag.Bits.MakeTempDir != 0)		/*�@TEMP�f�B���N�g���쐬�@*/
		{
			/*�@TEMP�f�B���N�g���Z�N�^�Ƀf�B���N�g���������݁@*/
			RtlCopyBytes((LPBYTE)((ULONG)(pEramExt->pPageBase) + (dwTempSector << SECTOR_LOG2)), &DirInit, sizeof(DirInit));
		}
	}
	KdPrint(("EramSetLabel end\n"));
	return TRUE;
}


/*�@GetExternalStart
		OS�Ǘ��O�������J�n�ʒu���o
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
	�߂�l
		����	TRUE:OS�Ǘ��O����������
*/

BOOLEAN GetExternalStart(
	IN PDRIVER_OBJECT	pDrvObj,
	IN PERAM_EXTENSION	pEramExt
 )
{
	/*�@���[�J���ϐ��@*/
	RTL_QUERY_REGISTRY_TABLE	ParamTable[2];
	NTSTATUS					ntStat;
	UNICODE_STRING				uniOption, uniOptionUp;
	PWSTR						pBuf, pwStr;
	ULONG						uSize, uMaxMem, loopi, uRemain, uNoLowMem, uStart;
	BOOLEAN						bStat, bNoLowMem;
	PHYSICAL_ADDRESS			phys;
	static WCHAR		szwMaxMem[] = L"MAXMEM=";
	static WCHAR		szwNoLowMem[] = L"NOLOWMEM";
	KdPrint(("GetExternalStart start\n"));
	uSize = 512 * sizeof(WCHAR);
	pBuf = ExAllocatePool(PagedPool, uSize);
	if (pBuf == NULL)		/*�@�m�ێ��s�@*/
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_OPTION_WORK_ALLOC_FAILED, NULL);
		return FALSE;
	}
	/*�@���擾�̈揀���@*/
	RtlInitUnicodeString(&uniOption, UNICODE_NULL);
	uniOption.Buffer = pBuf;
	uniOption.MaximumLength = (USHORT)uSize;
	/*�@���W�X�g���m�F�̈揉�����@*/
	RtlZeroBytes(&(ParamTable[0]), sizeof(ParamTable));
	ParamTable[0].Flags = RTL_QUERY_REGISTRY_DIRECT;
	ParamTable[0].Name = (PWSTR)L"SystemStartOptions";
	ParamTable[0].EntryContext = &uniOption;
	/*�@���W�X�g���l�ꊇ�₢���킹�@*/
	ntStat = RtlQueryRegistryValues(RTL_REGISTRY_CONTROL, NULL, &(ParamTable[0]), NULL, NULL);
	if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_OPTION_GET_FAILED, NULL);
		/*�@����������@*/
		ExFreePool(pBuf);
		return FALSE;
	}
	if (uniOption.Length == 0)	/*�@�I�v�V���������@*/
	{
		KdPrint(("No startup option\n"));
		/*�@����������@*/
		ExFreePool(pBuf);
		return FALSE;
	}
	/*�@�����A�h���X����/PAE���f�@*/
	uNoLowMem = 0;
	phys = MmGetPhysicalAddress(pBuf);
	if (phys.HighPart != 0)		/*�@over4GB�@*/
	{
		/*�@���Ȃ��Ƃ�/PAE�͑��݂��Ă���̂ŁA/NOLOWMEM��T���@*/
		uNoLowMem = sizeof(szwNoLowMem) - sizeof(WCHAR);
	}
	uMaxMem = sizeof(szwMaxMem) - sizeof(WCHAR);
	if (max(uMaxMem, uNoLowMem) >= uniOption.Length)	/*�@�I�v�V������MAXMEM/NOLOWMEM�͊܂܂�Ȃ��@*/
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_NO_OPTION, NULL);
		/*�@����������@*/
		ExFreePool(pBuf);
		return FALSE;
	}
	if (uNoLowMem == 0)
	{
		uNoLowMem = MAXDWORD;
	}
	KdPrint(("Startup option exist\n"));
	/*�@�啶���ϊ�(NT4�ł͊��ɂ���Ă���悤��)�@*/
	if (RtlUpcaseUnicodeString(&uniOptionUp , &uniOption, TRUE) != STATUS_SUCCESS)
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_CAPITAL_FAILED, NULL);
		/*�@����������@*/
		ExFreePool(pBuf);
		return FALSE;
	}
	/*�@����������@*/
	ExFreePool(pBuf);
	KdPrint(("Start Parse\n"));
	pwStr = uniOptionUp.Buffer;
	bStat = FALSE;
	bNoLowMem = FALSE;
	uStart = 0;
	uRemain = uniOptionUp.Length;
	for (loopi=0; loopi<(uniOptionUp.Length /sizeof(WCHAR)); loopi++, pwStr++, uRemain-=sizeof(WCHAR))
	{
		if ((uMaxMem < uRemain)&&
			(RtlCompareMemory(pwStr, szwMaxMem, uMaxMem) == uMaxMem))	/*�@��v�@*/
		{
			KdPrint(("Match, MAXMEM\n"));
			pwStr += (uMaxMem / sizeof(WCHAR));
			/*�@MAXMEM=n��n���擾�@*/
			if (GetMaxMem(pDrvObj, pEramExt, pwStr, &uStart) == FALSE)
			{
				EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "GetMaxMem");
			}
			if (uNoLowMem == MAXDWORD)
			{
				break;
			}
		}
		if ((uNoLowMem < uRemain)&&
			(RtlCompareMemory(pwStr, szwNoLowMem, uNoLowMem) == uNoLowMem))	/*�@��v�@*/
		{
			KdPrint(("Match, NOLOWMEM\n"));
			bNoLowMem = TRUE;
			break;
		}
	}
	KdPrint(("loop end\n"));
	if (bNoLowMem != FALSE)		/*�@/NOLOWMEM�@*/
	{
		/*�@17MB�����肩��g���Ă݂�@*/
		uStart = 17;
	}
	if (uStart != 0)	/*�@MAXMEM=n�܂���NOLOWMEM����@*/
	{
		bStat = CheckMaxMem(pDrvObj, pEramExt, uStart);
		if (bStat == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "CheckMaxMem");
		}
	}
	/*�@����������@*/
	RtlFreeUnicodeString(&uniOptionUp);
	if (bStat == FALSE)
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_INVALID, NULL);
	}
	KdPrint(("GetExternalStart end\n"));
	return bStat;
}


/*�@GetMaxMem
		MAXMEM=n�I�v�V�������
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		pwStr		MAXMEM=n��n�̕�����ւ̃|�C���^
		puSize		n���i�[����̈�ւ̃|�C���^
	�߂�l
		����
*/

BOOLEAN GetMaxMem(
	IN PDRIVER_OBJECT	pDrvObj,
	IN PERAM_EXTENSION	pEramExt,
	IN PWSTR			pwStr,
	OUT PULONG			puSize
 )
{
	/*�@���[�J���ϐ��@*/
	UNICODE_STRING	uniOptionMem;
	PWSTR			pwStrSp;
	pwStrSp = pwStr;
	while ((*pwStrSp != L' ')&&(*pwStrSp != L'\0'))
	{
		pwStrSp++;
	}
	*pwStrSp = L'\0';
	RtlInitUnicodeString(&uniOptionMem, pwStr);
	/*�@���l���@*/
	if (RtlUnicodeStringToInteger(&uniOptionMem, 0, puSize) != STATUS_SUCCESS)
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_ATOU, NULL);
		return FALSE;
	}
	return TRUE;
}


/*�@CheckMaxMem
		MAXMEM=n�I�v�V�������
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
		uSize		MAXMEM=n��n
	�߂�l
		����	TRUE:OS�Ǘ��O����������
*/

BOOLEAN CheckMaxMem(
	IN PDRIVER_OBJECT	pDrvObj,
	IN PERAM_EXTENSION	pEramExt,
	IN ULONG			uSize
 )
{
	if (uSize <= 16)		/*�@���������@*/
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_TOO_SMALL, NULL);
		return FALSE;
	}
	if (uSize >= 4095)		/*�@�傫�����@*/
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_TOO_BIG, NULL);
		return FALSE;
	}
	/*�@MB�P�ʕ␳�@*/
	pEramExt->uExternalStart /= SIZE_MEGABYTE;
	if (pEramExt->uExternalStart >= 4095)
	{
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_EXTSTART_TOO_BIG, NULL);
		return FALSE;
	}
	if (pEramExt->uExternalStart >= uSize)	/*�@��둤�ɕ␳�K�v�@*/
	{
		/*�@��둤�ɕ␳�@*/
		KdPrint(("System %dMB\n", uSize));
		uSize = pEramExt->uExternalStart;
	}
	pEramExt->uExternalStart = uSize * SIZE_MEGABYTE;
	KdPrint(("System %dMB, External start 0x%x\n", uSize, pEramExt->uExternalStart));
	uSize = pEramExt->uExternalStart / PAGE_SIZE_4K;
	if ((uSize + pEramExt->uSizeTotal) > (4096 * (SIZE_MEGABYTE / PAGE_SIZE_4K)))	/*�@over4GB�@*/
	{
		/*�@4GB�Ɏ��߂�(����1MB�͏��O�c)�@*/
		pEramExt->uSizeTotal = (4096 * (SIZE_MEGABYTE / PAGE_SIZE_4K)) - uSize;
	}
	return TRUE;
}


/*�@CheckExternalSize
		OS�Ǘ��O�������J�n�ʒu���o
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
	�߂�l
		����		TRUE:OS�Ǘ��O����������
*/

BOOLEAN CheckExternalSize(
	IN PDRIVER_OBJECT	pDrvObj,
	IN PERAM_EXTENSION	pEramExt
 )
{
	/*�@���[�J���ϐ��@*/
	CM_RESOURCE_LIST	ResList;	/*�@���\�[�X���X�g�@*/
	ULONG				uSize, uRealSize;
	BOOLEAN				bResConf, bStat;
	NTSTATUS			ntStat;
	DWORD				dwMaxAddr;
	ULARGE_INTEGER		ulMix;
	KdPrint(("CheckExternalSize start\n"));
	/*�@�m�ۂ��ׂ��o�C�g�����v�Z�@*/
	uSize = pEramExt->uSizeTotal * PAGE_SIZE_4K;
	if (uSize == 0)		/*�@�s���@*/
	{
		KdPrint(("Total is 0\n"));
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_DISK_SIZE_IS_0, NULL);
		return FALSE;
	}
	ulMix.QuadPart = (ULONGLONG)(pEramExt->uExternalStart) + (ULONGLONG)uSize;
	if (ulMix.HighPart != 0)	/*�@over4GB�@*/
	{
		uSize = (DWORD)(0 - (pEramExt->uExternalStart));
		pEramExt->uSizeTotal = uSize / PAGE_SIZE_4K;
		KdPrint(("Wrap 4GB, limit size 0x%x (%dpages)\n", uSize, pEramExt->uSizeTotal));
	}
	/*�@ACPI�\�񃁃��������@*/
	dwMaxAddr = GetAcpiReservedMemory(pDrvObj);
	KdPrint(("ACPI max 0x%x\n", dwMaxAddr));
	if (pEramExt->uExternalStart >= dwMaxAddr)	/*�@�J�n�ʒu��ACPI����������@*/
	{
		KdPrint(("Invalid start address\n"));
		EramReportEvent(pDrvObj, ERAMNT_ERROR_MAXMEM_NO_MEMORY, NULL);
		return FALSE;
	}
	if (ulMix.LowPart > dwMaxAddr)	/*�@ACPI�Əd�Ȃ�@*/
	{
		/*�@ACPI�̑O�܂łɐ����@*/
		uSize -= (ulMix.LowPart - dwMaxAddr);
		pEramExt->uSizeTotal = uSize / PAGE_SIZE_4K;
		ulMix.LowPart = dwMaxAddr;
		KdPrint(("Wrap ACPI, limit size 0x%x (%dpages)\n", uSize, pEramExt->uSizeTotal));
	}
	/*�@���\�[�X�v���ݒ�@*/
	ResourceInitTiny(pDrvObj, &ResList, pEramExt->uExternalStart, uSize);
	bResConf = FALSE;
	/*�@�������g�p�\���ǂ������ׂ�@*/
	if (pEramExt->uOptflag.Bits.SkipReportUsage == 0)
	{
		ntStat = IoReportResourceUsage(NULL, pDrvObj, &ResList, sizeof(ResList), NULL, NULL, 0, TRUE, &bResConf);
		if (ntStat != STATUS_SUCCESS)	/*�@���s�@*/
		{
			KdPrint(("IoReportResourceUsage failed, %x\n", ntStat));
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_REPORT_USAGE_FAILED, NULL);
			return FALSE;
		}
	}
	bStat = FALSE;
	if (bResConf != FALSE)	/*�@��������@*/
	{
		KdPrint(("Conflict\n"));
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_REPORT_USAGE_CONFLICT, NULL);
	}
	else
	{
		KdPrint(("No conflict\n"));
		if (CheckExternalMemoryExist(pDrvObj, pEramExt->uExternalStart, uSize, &uRealSize, dwMaxAddr) == FALSE)
		{
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "CheckExternalMemoryExist");
		}
		else
		{
			KdPrint(("extend memory 0x%08X - 0x%08X (0x%X bytes)\n", pEramExt->uExternalStart, (pEramExt->uExternalStart)+uRealSize-1, uRealSize));
			if (uSize > uRealSize)		/*�@�������s���@*/
			{
				/*�@���������͈̔͂ɂƂǂ߂�@*/
				pEramExt->uSizeTotal = uRealSize / PAGE_SIZE_4K;
				KdPrint(("size compress\n"));
				EramReportEvent(pEramExt->pDevObj, ERAMNT_WARN_MAXMEM_DISK_SIZE_FIXED, NULL);
			}
			bStat = TRUE;
		}
	}
	/*�@�h���C�o��������@*/
	if (pEramExt->uOptflag.Bits.SkipReportUsage == 0)
	{
		RtlZeroBytes(&ResList, sizeof(ResList));
		IoReportResourceUsage(NULL, pDrvObj, &ResList, sizeof(ResList), NULL, NULL, 0, FALSE, &bResConf);
	}
	KdPrint(("CheckExternalSize end\n"));
	return bStat;
}


/*�@ResourceInitTiny
		���\�[�X�}�b�v������
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pResList	���\�[�X�\���̂ւ̃|�C���^
		uStart		OS�Ǘ��O�������J�n�ʒu
		uSize		�f�B�X�N�ɉ񂷗e��
	�߂�l
		�Ȃ�
*/

VOID ResourceInitTiny(
	IN PDRIVER_OBJECT		pDrvObj,
	IN PCM_RESOURCE_LIST	pResList,
	IN ULONG				uStart,
	IN ULONG				uSize
 )
{
	/*�@���[�J���ϐ��@*/
	PCM_PARTIAL_RESOURCE_DESCRIPTOR	pDesc;
	PHYSICAL_ADDRESS				PortAdr;
	KdPrint(("ResourceInitTiny start\n"));
	PortAdr.HighPart = 0;
	/*�@�w�b�_���ݒ�@*/
	pResList->Count = 1;	/*�@Internal�̂݁@*/
	pResList->List[0].InterfaceType = Internal;
	pResList->List[0].BusNumber = 0;
	pResList->List[0].PartialResourceList.Count = 1;	/*�@�������@*/
	/*�@�f�B�X�N���v�^�擪�ւ̃|�C���^���擾�@*/
	pDesc = &(pResList->List[0].PartialResourceList.PartialDescriptors[0]);
	/*�@�����������v���̂��߂̐ݒ�@*/
	pDesc->Type = CmResourceTypeMemory;
	pDesc->ShareDisposition = CmResourceShareDriverExclusive;
	pDesc->Flags = CM_RESOURCE_MEMORY_READ_WRITE;
	PortAdr.LowPart  = uStart;
	pDesc->u.Memory.Start = PortAdr;
	pDesc->u.Memory.Length = uSize;
	KdPrint(("ResourceInitTiny end\n"));
}


/*�@CheckExternalMemoryExist
		�����������{��
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		uStart		OS�Ǘ��O�������J�n�ʒu
		uDiskSize	�f�B�X�N�ɉ񂷗e��
		puSize		�������e��
		dwMaxAddr	ACPI�g�p�������̍ŉ��ʃA�h���X
	�߂�l
		����
*/

BOOLEAN CheckExternalMemoryExist(
	IN PDRIVER_OBJECT	pDrvObj,
	IN ULONG			uStart,
	IN ULONG			uDiskSize,
	OUT PULONG			puSize,
	IN ULONG			dwMaxAddr
 )
{
	/*�@���[�J���ϐ��@*/
	ULONG				loopi, loopj;
	BOOLEAN				bExist;
	PHYSICAL_ADDRESS	MapAdr;
	volatile PBYTE		pBase;
	static BYTE			byTests[] = { 0, 0x55, 0xaa, 0 };
	KdPrint(("CheckExternalMemoryExist start\n"));
	/*�@�����g�p�ݒ�@*/
	if (ResourceSetupTiny(pDrvObj, uStart, &MapAdr) == FALSE)
	{
		KdPrint(("ResourceSetupTiny failed\n"));
		EramReportEvent(pDrvObj, ERAMNT_ERROR_FUNCTIONERROR, "ResourceSetupTiny");
		return FALSE;
	}
	KdPrint(("Memory check start\n"));
	*puSize = 0;
	for (loopi=0; loopi<uDiskSize; loopi+=SIZE_MEGABYTE)
	{
		/*�@�}�b�v�@*/
		pBase = (PBYTE)MmMapIoSpace(MapAdr, PAGE_SIZE_4K, FALSE);
		if (pBase == NULL)	/*�@�}�b�v�ȊOor�}�b�v���s�@*/
		{
			EramReportEvent(pDrvObj, ERAMNT_ERROR_MAXMEM_MAP_FAILED, NULL);
			return FALSE;
		}
		/*�@RAM���݌����@*/
		bExist = TRUE;
		for (loopj=0; loopj<sizeof(byTests); loopj++)
		{
			*pBase = byTests[loopj];
			if (*pBase != byTests[loopj])		/*�@�l���قȂ�cRAM�s�݁@*/
			{
				bExist = FALSE;
				break;
			}
		}
		/*�@�A���}�b�v�@*/
		MmUnmapIoSpace(pBase, PAGE_SIZE_4K);
		if (bExist == FALSE)	/*�@�s�݁@*/
		{
			break;
		}
		if ((uStart + loopi + SIZE_MEGABYTE) >= dwMaxAddr)	/*�@1MB�͋󂫖����@*/
		{
			KdPrint(("ACPI memory detected, adjusted\n"));
			*puSize += (dwMaxAddr - (uStart + loopi));
			break;
		}
		/*�@����1MB�ɐi�߂�@*/
		*puSize += SIZE_MEGABYTE;
		MapAdr.LowPart += SIZE_MEGABYTE;
	}
	if (*puSize == 0)		/*�@���o�ł����@*/
	{
		KdPrint(("extend memory 0 bytes\n"));
		EramReportEvent(pDrvObj, ERAMNT_ERROR_MAXMEM_NO_MEMORY, NULL);
		return FALSE;
	}
	KdPrint(("CheckExternalMemoryExist end, %dKB(=%dMB) detected\n", (*puSize) / SIZE_KILOBYTE, (*puSize) / SIZE_MEGABYTE));
	return TRUE;
}


/*�@ResourceSetupTiny
		I/O���\�[�X�����ݒ�
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		uStart		OS�Ǘ��O�������J�n�ʒu
		pMapAdr		�ϊ��A�h���X�ւ̃|�C���^
	�߂�l
		����
*/

BOOLEAN ResourceSetupTiny(
	IN PDRIVER_OBJECT		pDrvObj,
	IN ULONG				uStart,
	OUT PPHYSICAL_ADDRESS	pMapAdr
 )
{
	/*�@���[�J���ϐ��@*/
	PHYSICAL_ADDRESS	PortAdr;
	ULONG				MemType;
	KdPrint(("ResourceSetupTiny start\n"));
	PortAdr.HighPart = 0;
	/*�@�����������ݒ�@*/
	MemType = 0;			/*�@��������ԁ@*/
	PortAdr.LowPart  = uStart;
	/*�@�ꉞTranslate���Ă��邪���ʂ͓����͗l�@*/
	if (HalTranslateBusAddress(Internal, 0, PortAdr, &MemType, pMapAdr) == FALSE)
	{
		KdPrint(("Memory 0x%x, HalTranslateBusAddress failed\n", PortAdr.LowPart));
		EramReportEvent(pDrvObj, ERAMNT_ERROR_TRANSLATE_ADDRESS_FAILED, NULL);
		return FALSE;
	}
	if (MemType != 0)		/*�@�}�b�v�@*/
	{
		KdPrint(("!Map type\n"));
		EramReportEvent(pDrvObj, ERAMNT_ERROR_PORT_MAPPED, NULL);
		return FALSE;
	}
	KdPrint(("ResourceSetupTiny end\n"));
	return TRUE;
}


/*�@ExtReport
		OS�Ǘ��O�������J�n�ʒu���o
	����
		pDrvObj		���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		pEramExt	ERAM_EXTENTION�\���̂ւ̃|�C���^
	�߂�l
		����
*/

BOOLEAN ExtReport(
	IN PDRIVER_OBJECT	pDrvObj,
	IN PERAM_EXTENSION	pEramExt
 )
{
	/*�@���[�J���ϐ��@*/
	CM_RESOURCE_LIST	ResList;	/*�@���\�[�X���X�g�@*/
	ULONG				uSize;
	BOOLEAN				bResConf;
	NTSTATUS			ntStat;
	KdPrint(("ExtReport start\n"));
	/*�@�m�ۂ��ׂ��o�C�g�����v�Z�@*/
	uSize = pEramExt->uSizeTotal * PAGE_SIZE_4K;
	if (uSize == 0)		/*�@�s���@*/
	{
		KdPrint(("Total is 0\n"));
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_DISK_SIZE_IS_0, NULL);
		return FALSE;
	}
	/*�@���\�[�X�v���ݒ�@*/
	ResourceInitTiny(pDrvObj, &ResList, pEramExt->uExternalStart, uSize);
	/*�@�����g�p��ʒm�@*/
	if (pEramExt->uOptflag.Bits.SkipReportUsage == 0)
	{
		ntStat = IoReportResourceUsage(NULL, pDrvObj, &ResList, sizeof(ResList), NULL, NULL, 0, FALSE, &bResConf);
		if ((ntStat == STATUS_SUCCESS)&&
			(bResConf != FALSE))	/*�@���������@*/
		{
			KdPrint(("Conflict\n"));
			/*�@�G���[��ݒ�@*/
			ntStat = STATUS_DEVICE_CONFIGURATION_ERROR;
		}
		if (ntStat != STATUS_SUCCESS)	/*�@�g�p�s�@*/
		{
			KdPrint(("IoReportResourceUsage failed, %x\n", ntStat));
			EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_MAXMEM_REPORT_USAGE_FAILED, NULL);
			return FALSE;
		}
	}
	/*�@�����g�p�ݒ�@*/
	if (ResourceSetupTiny(pDrvObj, pEramExt->uExternalStart, &(pEramExt->MapAdr)) == FALSE)
	{
		KdPrint(("ResourceSetupTiny failed\n"));
		EramReportEvent(pEramExt->pDevObj, ERAMNT_ERROR_FUNCTIONERROR, "ResourceSetupTiny");
		/*�@�h���C�o��������@*/
		if (pEramExt->uOptflag.Bits.SkipReportUsage == 0)
		{
			RtlZeroBytes(&ResList, sizeof(ResList));
			IoReportResourceUsage(NULL, pDrvObj, &ResList, sizeof(ResList), NULL, NULL, 0, FALSE, &bResConf);
		}
		return FALSE;
	}
	KdPrint(("ExtReport end\n"));
	return TRUE;
}


/*�@GetAcpiReservedMemory
		ACPI�\�񃁃�������
	����
		pDrvObj			���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
	�߂�l
		ACPI�g�p�������̍ŉ��ʃA�h���X
*/

DWORD GetAcpiReservedMemory(
	IN PDRIVER_OBJECT	pDrvObj
 )
{
	/*�@���[�J���ϐ��@*/
	ULONG				loopi;
	PHYSICAL_ADDRESS	MapAdr;
	PBYTE				pBase;
	PDWORD				pdwBios;
	DWORD				dwMaxAdr;
	KdPrint(("GetAcpiReservedMemory start\n"));
	dwMaxAdr = 0xffff0000;
	/*�@�����g�p�ݒ�@*/
	if (ResourceSetupTiny(pDrvObj, BIOS_ADDRESS_START, &MapAdr) == FALSE)
	{
		KdPrint(("ResourceSetupTiny failed\n"));
		EramReportEvent(pDrvObj, ERAMNT_ERROR_FUNCTIONERROR, "ResourceSetupTiny");
		return dwMaxAdr;
	}
	/*�@�}�b�v(�L���b�V������)�@*/
	pBase = (PBYTE)MmMapIoSpace(MapAdr, BIOS_SIZE, TRUE);
	if (pBase == NULL)	/*�@�}�b�v�ȊOor�}�b�v���s�@*/
	{
		EramReportEvent(pDrvObj, ERAMNT_ERROR_MAXMEM_MAP_FAILED, NULL);
		return dwMaxAdr;
	}
	pdwBios = (PDWORD)pBase;
	for (loopi=0; loopi<BIOS_SIZE; loopi+=16)
	{
		if ((pdwBios[0] == 0x20445352)&&	/*�@'RSD PTR '�@*/
			(pdwBios[1] == 0x20525450))
		{
			KdPrint(("RSDT found, 0x%X\n", pdwBios[4]));
			if (pdwBios[4] != 0)	/*�@32bit�A�h���X�L���@*/
			{
				/*�@RSDT�̐�𒲂ׂ�@*/
				dwMaxAdr = CheckAcpiRsdt(pDrvObj, dwMaxAdr, pdwBios[4]) & 0xffff0000;
			}
			break;
		}
		pdwBios = &(pdwBios[4]);
	}
	/*�@�A���}�b�v�@*/
	MmUnmapIoSpace(pBase, BIOS_SIZE);
	return dwMaxAdr;
}


/*�@CheckAcpiRsdt
		RSDT����
	����
		pDrvObj			���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		dwMinValue		ACPI�g�p�������̍ŉ��ʃA�h���X
		dwRsdt			RSDT�̃A�h���X
	�߂�l
		ACPI�g�p�������̍ŉ��ʃA�h���X
*/

DWORD CheckAcpiRsdt(
	IN PDRIVER_OBJECT	pDrvObj,
	IN DWORD			dwMinValue,
	IN DWORD			dwRsdt
 )
{
	/*�@���[�J���ϐ��@*/
	static ULONG		uRsdtSize = PAGE_SIZE_4K * 2;
	ULONG				loopi, uCnt;
	PHYSICAL_ADDRESS	MapAdr;
	PBYTE				pBase;
	PDWORD				pdwRsdt;
	DWORD				dwRsdtBase, dwRsdtOfs;
	KdPrint(("CheckAcpiRsdt start\n"));
	dwRsdtBase = dwRsdt & ~(PAGE_SIZE_4K - 1);
	dwRsdtOfs = dwRsdt - dwRsdtBase;
	dwMinValue = dwRsdt;
	/*�@�����g�p�ݒ�@*/
	if (ResourceSetupTiny(pDrvObj, dwRsdtBase, &MapAdr) == FALSE)
	{
		KdPrint(("ResourceSetupTiny failed\n"));
		EramReportEvent(pDrvObj, ERAMNT_ERROR_FUNCTIONERROR, "ResourceSetupTiny");
		return dwMinValue;
	}
	/*�@�}�b�v(�L���b�V������)�@*/
	pBase = (PBYTE)MmMapIoSpace(MapAdr, uRsdtSize, TRUE);
	if (pBase == NULL)	/*�@�}�b�v�ȊOor�}�b�v���s�@*/
	{
		EramReportEvent(pDrvObj, ERAMNT_ERROR_MAXMEM_MAP_FAILED, NULL);
		return dwMinValue;
	}
	pdwRsdt = (PDWORD)((DWORD)pBase + dwRsdtOfs);
	if ((pdwRsdt[0] != 0x54445352)||	/*�@'RSDT'�@*/
		(pdwRsdt[1] < 0x24))
	{
		KdPrint(("!RSDT\n"));
		return dwMinValue;
	}
	KdPrint(("RSDT found, 0x%X\n", dwRsdt));
	uCnt = ((pdwRsdt[1] - 0x24) / sizeof(DWORD));
	pdwRsdt = &(pdwRsdt[0x24 / sizeof(DWORD)]);
	/*�@�z�񕪌J��Ԃ��@*/
	for (loopi=0; loopi<uCnt; loopi++, pdwRsdt++)
	{
		dwMinValue = CheckRsdtElements(pDrvObj, dwMinValue, *pdwRsdt);
	}
	/*�@�A���}�b�v�@*/
	MmUnmapIoSpace(pBase, uRsdtSize);
	KdPrint(("CheckAcpiRsdt end, 0x%X\n", dwMinValue));
	return dwMinValue;
}


/*�@CheckRsdtElements
		RSDT�v�f����
	����
		pDrvObj			���u�̑�\�I�u�W�F�N�g�ւ̃|�C���^
		dwMinValue		ACPI�g�p�������̍ŉ��ʃA�h���X
		dwRsdtElement	RSDT�z��v�f�̃A�h���X
	�߂�l
		ACPI�g�p�������̍ŉ��ʃA�h���X
*/

DWORD CheckRsdtElements(
	IN PDRIVER_OBJECT	pDrvObj,
	IN DWORD			dwMinValue,
	IN DWORD			dwRsdtElement
 )
{
	/*�@���[�J���ϐ��@*/
	static ULONG		uRsdtSize = PAGE_SIZE_4K * 2;
	PHYSICAL_ADDRESS	MapAdr;
	PBYTE				pBase;
	PDWORD				pdwRsdt;
	DWORD				dwRsdtBase, dwRsdtOfs;
	KdPrint(("CheckRsdtElements start, min=0x%X, elem=0x%X\n", dwMinValue, dwRsdtElement));
	if (dwRsdtElement == 0)
	{
		return dwMinValue;
	}
	dwRsdtBase = dwRsdtElement & ~(PAGE_SIZE_4K - 1);
	dwRsdtOfs = dwRsdtElement - dwRsdtBase;
	dwMinValue = (dwMinValue > dwRsdtElement) ? dwRsdtElement : dwMinValue;
	/*�@�����g�p�ݒ�@*/
	if (ResourceSetupTiny(pDrvObj, dwRsdtBase, &MapAdr) == FALSE)
	{
		KdPrint(("ResourceSetupTiny failed\n"));
		EramReportEvent(pDrvObj, ERAMNT_ERROR_FUNCTIONERROR, "ResourceSetupTiny");
		return dwMinValue;
	}
	/*�@�}�b�v(�L���b�V������)�@*/
	pBase = (PBYTE)MmMapIoSpace(MapAdr, uRsdtSize, TRUE);
	if (pBase == NULL)	/*�@�}�b�v�ȊOor�}�b�v���s�@*/
	{
		EramReportEvent(pDrvObj, ERAMNT_ERROR_MAXMEM_MAP_FAILED, NULL);
		return dwMinValue;
	}
	pdwRsdt = (PDWORD)((DWORD)pBase + dwRsdtOfs);
	KdPrint(("Element 0x%X\n", *pdwRsdt));
	if ((pdwRsdt[0] == 0x50434146)&&	/*�@'FACP'�@*/
		(pdwRsdt[1] >= 0x74))
	{
		/*�@FADT�����@*/
		if (pdwRsdt[9] != 0)
		{
			dwMinValue = (dwMinValue > pdwRsdt[9]) ? pdwRsdt[9] : dwMinValue;
		}
		if (pdwRsdt[10] != 0)
		{
			dwMinValue = (dwMinValue > pdwRsdt[10]) ? pdwRsdt[10] : dwMinValue;
		}
		KdPrint(("FADT found, FACS=0x%X, DSDT=0x%X\n", pdwRsdt[9], pdwRsdt[10]));
	}
	/*�@�A���}�b�v�@*/
	MmUnmapIoSpace(pBase, uRsdtSize);
	KdPrint(("CheckRsdtElements end, min 0x%X\n", dwMinValue));
	return dwMinValue;
}

