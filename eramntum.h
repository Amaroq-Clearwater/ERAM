//
//	ERAMNT�p���b�Z�[�W��`
//
//	�w�b�_
//	���b�Z�[�W��`
//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: ERAMNT_ERROR_FUNCTIONERROR
//
// MessageText:
//
//  �֐�%2�Ŏ��s���Ԃ���܂���.%0
//
#define ERAMNT_ERROR_FUNCTIONERROR       ((NTSTATUS)0xE0FF0001L)

//
// MessageId: ERAMNT_ERROR_MAXMEM_ALREADY_FREE
//
// MessageText:
//
//  OS�Ǘ��O��؂����ɉ������Ă��܂�.%0
//
#define ERAMNT_ERROR_MAXMEM_ALREADY_FREE ((NTSTATUS)0xE0FF0002L)

//
// MessageId: ERAMNT_ERROR_MAXMEM_MAP_FAILED
//
// MessageText:
//
//  OS�Ǘ��O��؂�ϯ�ߎ��s.%0
//
#define ERAMNT_ERROR_MAXMEM_MAP_FAILED   ((NTSTATUS)0xE0FF0003L)

//
// MessageId: ERAMNT_ERROR_MAXMEM_REPORT_USAGE_FAILED
//
// MessageText:
//
//  OS�Ǘ��O��؂̎g�p�ʒm���s.%0
//
#define ERAMNT_ERROR_MAXMEM_REPORT_USAGE_FAILED ((NTSTATUS)0xE0FF0004L)

//
// MessageId: ERAMNT_ERROR_MAXMEM_REPORT_USAGE_CONFLICT
//
// MessageText:
//
//  OS�Ǘ��O��؂̈ꕔ�́A�������޲��ɂ��g�p����Ă��܂�.�ި�����ނ����������Ă݂Ă�������.%0
//
#define ERAMNT_ERROR_MAXMEM_REPORT_USAGE_CONFLICT ((NTSTATUS)0xE0FF0005L)

//
// MessageId: ERAMNT_ERROR_CREATE_THREAD
//
// MessageText:
//
//  ���ѽگ�ނ̍쐬�Ɏ��s���܂���.%0
//
#define ERAMNT_ERROR_CREATE_THREAD       ((NTSTATUS)0xE0FF0006L)

//
// MessageId: ERAMNT_ERROR_MAXMEM_NO_MEMORY
//
// MessageText:
//
//  OS�Ǘ��O��؂͌��o����܂���ł���.%0
//
#define ERAMNT_ERROR_MAXMEM_NO_MEMORY    ((NTSTATUS)0xE0FF0007L)

//
// MessageId: ERAMNT_ERROR_MAXMEM_NOT_DETECTED
//
// MessageText:
//
//  OS�Ǘ��O��؂�������܂���.%0
//
#define ERAMNT_ERROR_MAXMEM_NOT_DETECTED ((NTSTATUS)0xE0FF0008L)

//
// MessageId: ERAMNT_ERROR_OPTION_WORK_ALLOC_FAILED
//
// MessageText:
//
//  OS�N����߼�ݗp��؊m�ێ��s.%0
//
#define ERAMNT_ERROR_OPTION_WORK_ALLOC_FAILED ((NTSTATUS)0xE0FF0009L)

//
// MessageId: ERAMNT_ERROR_OPTION_GET_FAILED
//
// MessageText:
//
//  OS�N����߼�ݎ擾���s.%0
//
#define ERAMNT_ERROR_OPTION_GET_FAILED   ((NTSTATUS)0xE0FF000AL)

//
// MessageId: ERAMNT_ERROR_MAXMEM_NO_OPTION
//
// MessageText:
//
//  �N����߼�݂�%bMAXMEM=n%b������܂���.%0
//
#define ERAMNT_ERROR_MAXMEM_NO_OPTION    ((NTSTATUS)0xE0FF000BL)

//
// MessageId: ERAMNT_ERROR_MAXMEM_CAPITAL_FAILED
//
// MessageText:
//
//  �N����߼�ݑ啶�������s.%0
//
#define ERAMNT_ERROR_MAXMEM_CAPITAL_FAILED ((NTSTATUS)0xE0FF000CL)

//
// MessageId: ERAMNT_ERROR_MAXMEM_ATOU
//
// MessageText:
//
//  MAXMEM���l�����s.%0
//
#define ERAMNT_ERROR_MAXMEM_ATOU         ((NTSTATUS)0xE0FF000DL)

//
// MessageId: ERAMNT_ERROR_MAXMEM_TOO_SMALL
//
// MessageText:
//
//  MAXMEM��17�ȏ���w�肵�Ă�������.%0
//
#define ERAMNT_ERROR_MAXMEM_TOO_SMALL    ((NTSTATUS)0xE0FF000EL)

//
// MessageId: ERAMNT_ERROR_MAXMEM_TOO_BIG
//
// MessageText:
//
//  MAXMEM��4095�������w�肵�Ă�������.%0
//
#define ERAMNT_ERROR_MAXMEM_TOO_BIG      ((NTSTATUS)0xE0FF000FL)

//
// MessageId: ERAMNT_ERROR_MAXMEM_INVALID
//
// MessageText:
//
//  �N����߼�݂� MAXMEM=n ���������A�s���Ȓl�ł�.%0
//
#define ERAMNT_ERROR_MAXMEM_INVALID      ((NTSTATUS)0xE0FF0010L)

//
// MessageId: ERAMNT_ERROR_EXTSTART_TOO_BIG
//
// MessageText:
//
//  ExtStart��4095MB�������w�肵�Ă�������.%0
//
#define ERAMNT_ERROR_EXTSTART_TOO_BIG    ((NTSTATUS)0xE0FF0011L)

//
// MessageId: ERAMNT_ERROR_WORK_ALLOC_FAILED
//
// MessageText:
//
//  ��Ɨp��؊m�ێ��s.%0
//
#define ERAMNT_ERROR_WORK_ALLOC_FAILED   ((NTSTATUS)0xE0FF0012L)

//
// MessageId: ERAMNT_ERROR_REG_KEY_APPEND_FAILED
//
// MessageText:
//
//  ڼ޽�ط������񍇐����s.%0
//
#define ERAMNT_ERROR_REG_KEY_APPEND_FAILED ((NTSTATUS)0xE0FF0013L)

//
// MessageId: ERAMNT_ERROR_CREATE_DEVICE_FAILED
//
// MessageText:
//
//  ���޲��쐬���s.%0
//
#define ERAMNT_ERROR_CREATE_DEVICE_FAILED ((NTSTATUS)0xE0FF0014L)

//
// MessageId: ERAMNT_ERROR_DISK_SIZE_TOO_SMALL
//
// MessageText:
//
//  �ި���ւ̊��蓖����؂����������܂�.%0
//
#define ERAMNT_ERROR_DISK_SIZE_TOO_SMALL ((NTSTATUS)0xE0FF0015L)

//
// MessageId: ERAMNT_ERROR_DEVICE_NAME_ALLOC_FAILED
//
// MessageText:
//
//  ���޲����̈�m�ێ��s.%0
//
#define ERAMNT_ERROR_DEVICE_NAME_ALLOC_FAILED ((NTSTATUS)0xE0FF0016L)

//
// MessageId: ERAMNT_ERROR_CREATE_SYMBOLIC_LINK_FAILED
//
// MessageText:
//
//  ����د��ݸ�쐬���s.%0
//
#define ERAMNT_ERROR_CREATE_SYMBOLIC_LINK_FAILED ((NTSTATUS)0xE0FF0017L)

//
// MessageId: ERAMNT_ERROR_DISK_ALLOC_FAILED
//
// MessageText:
//
//  �ި���p��؊m�ێ��s.%0
//
#define ERAMNT_ERROR_DISK_ALLOC_FAILED   ((NTSTATUS)0xE0FF0018L)

//
// MessageId: ERAMNT_ERROR_DISK_SIZE_IS_0
//
// MessageText:
//
//  �m�ۗe�ʂ�0�ł�.%0
//
#define ERAMNT_ERROR_DISK_SIZE_IS_0      ((NTSTATUS)0xE0FF0019L)

//
// MessageId: ERAMNT_ERROR_TRANSLATE_ADDRESS_FAILED
//
// MessageText:
//
//  OS�Ǘ����ڽ�ւ̕ϊ��Ɏ��s.%0
//
#define ERAMNT_ERROR_TRANSLATE_ADDRESS_FAILED ((NTSTATUS)0xE0FF001AL)

//
// MessageId: ERAMNT_ERROR_PORT_MAPPED
//
// MessageText:
//
//  I/O��Ԃ�ϯ�߂ɂ͑Ή����Ă��܂���.%0
//
#define ERAMNT_ERROR_PORT_MAPPED         ((NTSTATUS)0xE0FF001BL)

//
// MessageId: ERAMNT_ERROR_CREATE_EXT_FILE
//
// MessageText:
//
//  �O��̧�ق̍쐬�Ɏ��s���܂���.%0
//
#define ERAMNT_ERROR_CREATE_EXT_FILE     ((NTSTATUS)0xE0FF001CL)

//
// MessageId: ERAMNT_ERROR_SET_INFO_EXT_FILE
//
// MessageText:
//
//  �O��̧�ق̻��ޒ����Ɏ��s���܂���.%0
//
#define ERAMNT_ERROR_SET_INFO_EXT_FILE   ((NTSTATUS)0xE0FF001DL)

//
// MessageId: ERAMNT_ERROR_CREATE_EXT_FILE_SECTION
//
// MessageText:
//
//  �O��̧�ق̾���ݍ쐬�Ɏ��s���܂���.%0
//
#define ERAMNT_ERROR_CREATE_EXT_FILE_SECTION ((NTSTATUS)0xE0FF001EL)

//
// MessageId: ERAMNT_ERROR_MAP_EXT_FILE
//
// MessageText:
//
//  �O��̧�ق�ϯ�߂Ɏ��s���܂���.%0
//
#define ERAMNT_ERROR_MAP_EXT_FILE        ((NTSTATUS)0xE0FF001FL)

//
// MessageId: ERAMNT_ERROR_GET_THREAD_OBJECT
//
// MessageText:
//
//  ���ѽگ�ނ̵�޼ު�Ď擾�Ɏ��s���܂���.%0
//
#define ERAMNT_ERROR_GET_THREAD_OBJECT   ((NTSTATUS)0xE0FF0020L)

//
// MessageId: ERAMNT_WARN_MAXMEM_DISK_SIZE_FIXED
//
// MessageText:
//
//  OS�Ǘ��O��؂����Ȃ��̂�RAM�ި���͏k������܂���.%0
//
#define ERAMNT_WARN_MAXMEM_DISK_SIZE_FIXED ((NTSTATUS)0xA0FF0006L)

//
// MessageId: ERAMNT_INF_MEMORY_SIZE
//
// MessageText:
//
//  %2KB���x�m�ۉ\�Ǝv���܂�.%0
//
#define ERAMNT_INF_MEMORY_SIZE           ((NTSTATUS)0x60FF001CL)

