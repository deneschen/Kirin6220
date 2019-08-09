/******************************************************************************

    Copyright(C)2008,Hisilicon Co. LTD.

 ******************************************************************************
  File Name       : LnasErrLogInterface.h
  Description     : LnasErrLogInterface.h header file
  History         :
     1.HANLUFENG 41410       2013-8-27     Draft Enact
     2.
******************************************************************************/

#ifndef __LNASERRLOGINTERFACE_H__
#define __LNASERRLOGINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include    "omerrorlog.h"
#include    "LnasFtmInterface.h"

#pragma  pack(4)

/*****************************************************************************
  2 macro
*****************************************************************************/
#define LNAS_OM_ERRLOG_ID_ESM_REJ_CN_CAUSE               (400)
#define LNAS_OM_ERRLOG_ID_EMM_FAIL_CAUSE                 (600)
#define LNAS_OM_ERRLOG_ID_EMM_REJ_CN_CAUSE               (800)
#define LNAS_ERR_LOG_CTRL_LEVEL_NULL                     (0)                     /* ErrLog�ȼ�δ����*/
#define LNAS_ERR_LOG_CTRL_LEVEL_CRITICAL                 (1)                     /* ErrLog�ȼ�Ϊ���� */
#define LNAS_ERR_LOG_CTRL_LEVEL_MAJOR                    (2)                     /* ErrLog�ȼ�Ϊ��Ҫ */
#define LNAS_ERR_LOG_CTRL_LEVEL_MINOR                    (3)                     /* ErrLog�ȼ�Ϊ��Ҫ */
#define LNAS_ERR_LOG_CTRL_LEVEL_WARNING                  (4)                     /* ErrLog�ȼ�Ϊ��ʾ */
#define NAS_EMM_RING_BUFFER_SIZE                        (1024 * 2)               /* LNAS�Ļ��ι��������С */


/*****************************************************************************
  3 Massage Declare
*****************************************************************************/


/*****************************************************************************
  4 Enum
*****************************************************************************/
/*****************************************************************************
 ö����    : EMM_OM_ERRLOG_ALM_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : �澯��������
*****************************************************************************/
enum EMM_OM_ERRLOG_TYPE_ENUM
{
    EMM_OM_ERRLOG_TYPE_CN_REJ          = 1, /*CN REJ����*/

    EMM_OM_ERRLOG_TYPE_CN_BUTT
};
typedef VOS_UINT16 EMM_OM_ERRLOG_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : EMM_OM_ERRLOG_ALM_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : �澯��������
*****************************************************************************/
enum EMM_OM_ERRLOG_ALM_TYPE_ENUM
{
    EMM_OM_ERRLOG_ALM_TYPE_COMMUNICATION    = 0x01,                               /* ͨ�� */
    EMM_OM_ERRLOG_ALM_TYPE_TRAFFIC_QUALITY  = 0x02,                               /* ҵ������ */
    EMM_OM_ERRLOG_ALM_TYPE_DEAL_WRONG       = 0x03,                               /* �������� */
    EMM_OM_ERRLOG_ALM_TYPE_DEVICE_FAILURE   = 0x04,                               /* �豸���� */
    EMM_OM_ERRLOG_ALM_TYPE_ENV_FAILURE      = 0x05,                               /* �������� */
    EMM_OM_ERRLOG_ALM_TYPE_BUTT
};
typedef VOS_UINT16  EMM_OM_ERRLOG_ALM_TYPE_ENUM_U16;

/*****************************************************************************
 ö����    : EMM_OM_ERRLOG_PAGING_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : EMM_OM_ERRLOG_PAGING_ENUM enPagingUeIdȡֵ
*****************************************************************************/
enum EMM_OM_ERRLOG_PAGING_ENUM
{
    EMM_OM_ERRLOG_PAGING_PS_IMSI          = 1, /*IMSI PAGING*/

    EMM_OM_ERRLOG_PAGING_UE_ID_BUTT
};
typedef VOS_UINT16 EMM_OM_ERRLOG_PAGING_ENUM_UINT16;

/*****************************************************************************
 ö����    :  EMM_OM_ERRLOG_RAT_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : �����ĳһ��ϵͳ������Ŀǰֻ�õ�W2L���˵�ϵͳ��Ϣ��ʱ
*****************************************************************************/
enum EMM_OM_ERRLOG_RAT_ENUM
{
    EMM_OM_ERRLOG_REVERSE_WAIT_SYSINFO_TIMEOUT_PROCEDURE    = 1,     /*��ϵͳ���˵ȴ���ʱ����ʱ*/

    EMM_OM_ERRLOG_INFO_TYPE_BUTT
};
typedef VOS_UINT16  EMM_OM_ERRLOG_RAT_ENUM_UINT16;

/*****************************************************************************
 �ṹ����   :ESM_OM_ERRLOG_ID_ENUM
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   :ESM���ԭ��ֵ
*****************************************************************************/
enum ESM_OM_ERRLOG_ID_ENUM
{
    /*ESMģ��ʧ�ܾܾ�*/
    ESM_OM_ERRLOG_CAUSE_OPERATOR_DETERMINE_BARRING = LNAS_OM_ERRLOG_ID_ESM_REJ_CN_CAUSE, /* ����ܾ�����ʾ��������ֹ */
    ESM_OM_ERRLOG_CAUSE_INSUFFICIENT_RESOURCES,             /* ����ܾ�,��ʾ��Դ����        */
    ESM_OM_ERRLOG_CAUSE_UNKNOWN_OR_MISSING_APN,             /* ����ܾ�,��ʾAPN�޷�ʶ��     */
    ESM_OM_ERRLOG_CAUSE_UNKNOWN_PDN_TYPE,                   /* ����ܾ�����ʾPDN�����޷�ʶ��*/
    ESM_OM_ERRLOG_CAUSE_USER_AUTH_FAIL,                     /* ����ܾ�����ʾ�û���Ȩʧ��   */
    ESM_OM_ERRLOG_CAUSE_REQ_REJ_BY_SGW_OR_PGW,              /* ����ܾ�����ʾSGW����PGW�ܾ��û����� */
    ESM_OM_ERRLOG_CAUSE_REQ_REJ_UNSPECITY,                  /* ����ܾ���ԭ���� */
    ESM_OM_ERRLOG_CAUSE_SERVICE_OPTION_NOT_SUPPORT,         /* ����ܾ�����ʾ����ѡ�֧�� */
    ESM_OM_ERRLOG_CAUSE_REQ_SERVICE_NOT_SUBSCRIBED,         /* ����ܾ�����ʾ����ѡ��û��ǩԼ */
    ESM_OM_ERRLOG_CAUSE_SERVICE_OPTION_TEMP_OUT_ORDER,      /* ����ܾ�����ʾ����ѡ����ʱ�Բ�֧��*/
    ESM_OM_ERRLOG_CAUSE_PTI_ALREADY_IN_USED,                /* ����ܾ�����ʾPTI��ʹ��*/
    ESM_OM_ERRLOG_CAUSE_REGULAR_DEACTIVATION,               /* ����ܾ�����ʾ����ȥ����*/
    ESM_OM_ERRLOG_CAUSE_EPS_QOS_NOT_ACCEPT,                 /* ����ܾ�����ʾQosδ������*/
    ESM_OM_ERRLOG_CAUSE_NETWORK_FAILURE,                    /* ����ܾ�����ʾ�������*/
    ESM_OM_ERRLOG_CAUSE_REACTIVATION_REQUESTED,             /* ����ܾ�����ʾ��Ҫ���¼���*/
    ESM_OM_ERRLOG_CAUSE_SEMANTIC_ERR_IN_TFT,                /* ����ܾ�����ʾTFT�������*/
    ESM_OM_ERRLOG_CAUSE_SYNTACTIC_ERR_IN_TFT,               /* ����ܾ�����ʾTFT�﷨����*/
    ESM_OM_ERRLOG_CAUSE_INVALID_EPS_BEARER_IDENTITY,        /* ����ܾ�����ʾ�Ƿ��ĳ��ر�ʶ*/
    ESM_OM_ERRLOG_CAUSE_SEMANTIC_ERR_IN_PACKET_FILTER,      /* ����ܾ�����ʾPacketFilter�������*/
    ESM_OM_ERRLOG_CAUSE_SYNCTACTIC_ERR_IN_PACKET_FILTER,    /* ����ܾ�����ʾPacketFilter�﷨����*/
    ESM_OM_ERRLOG_CAUSE_BEARER_WITHOUT_TFT_ACT,             /* ����ܾ�����ʾ�����������û��TFT�ĳ���*/
    ESM_OM_ERRLOG_CAUSE_PTI_MISMATCH,                       /* ����ܾ�����ʾPTI��ƥ��*/
    ESM_OM_ERRLOG_CAUSE_LAST_PDN_DISCONN_NOT_ALLOWED,       /* ����ܾ�����ʾ����PDN�������ͷ�*/
    ESM_OM_ERRLOG_CAUSE_PDNTYPE_IPV4_ONLY_ALLOWED,          /* ����ܾ�����ʾPDN����ֻ����IpV4*/
    ESM_OM_ERRLOG_CAUSE_PDNTYPE_IPV6_ONLY_ALLOWED,          /* ����ܾ�����ʾPDN����ֻ����IpV6*/
    ESM_OM_ERRLOG_CAUSE_SINGLE_ADDR_BEARER_ONLY_ALLOWED,    /* ����ܾ�����ʾPDNֻ��������IP��ַ*/
    ESM_OM_ERRLOG_CAUSE_ESM_INFORMATION_NOT_RECEIVED,       /* ����ܾ�����ʾESM Info��Ϣû���յ�*/
    ESM_OM_ERRLOG_CAUSE_PDN_CONNECTION_DOES_NOT_EXIST,      /* ����ܾ�����ʾPDN���Ӳ�����*/
    ESM_OM_ERRLOG_CAUSE_SAME_APN_MULTI_PDN_CONNECTION_NOT_ALLOWED, /* ����ܾ�����ʾ��PDN��������Ӧͬһ��APN*/
    ESM_OM_ERRLOG_CAUSE_COLLISION_WITH_NETWORK_INITIATED_REQUEST,  /* ����ܾ�����ʾ�����紥���������ͻ*/
    ESM_OM_ERRLOG_CAUSE_UNSUPPORTED_QCI_VALUE,              /* ����ܾ�����ʾQCI��ֵ�޷�֧��*/
    ESM_OM_ERRLOG_CAUSE_INVALID_PTI_VALUE,                  /* ����ܾ�����ʾPTI��ֵ������*/
    ESM_OM_ERRLOG_CAUSE_SEMANTICALLY_INCORRECT_MESSAGE,     /* ����ܾ�����ʾ��Ϣ���岻��ȷ*/
    ESM_OM_ERRLOG_CAUSE_INVALID_MANDATORY_INFORMATION,      /* ����ܾ�����ʾ��ѡ��Ԫ����ȷ*/
    ESM_OM_ERRLOG_CAUSE_MESSAGE_TYPE_NON_EXIST_OR_NOT_IMPLEMENTED, /* ����ܾ�����ʾ��Ϣ���Ͳ����ڻ򲻿���*/
    ESM_OM_ERRLOG_CAUSE_MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROT_STA, /* ����ܾ�����ʾ��Ϣ������Э�鲻һ��*/
    ESM_OM_ERRLOG_CAUSE_INFO_ELEMENT_NON_EXIST_OR_NOT_IMPLEMENTED, /* ����ܾ�����ʾ��Ԫ�����ڻ򲻿���*/
    ESM_OM_ERRLOG_CAUSE_CONDITIONAL_IE_ERROR,               /* ����ܾ�����ʾ������Ԫ����*/
    ESM_OM_ERRLOG_CAUSE_MESSAGE_NOT_COMPATIBLE_WITH_PROT_STA, /* ����ܾ�����ʾ��Ϣ��Э��涨��һ��*/
    ESM_OM_ERRLOG_CAUSE_PROTOCOL_ERROR,                     /* ����ܾ�����ʾ��ָ����Э�����*/
    ESM_OM_ERRLOG_CAUSE_APN_RESTRICTION_VAL_INCOMPATIBLE_WITH_ACT_BEARER, /* ����ܾ�����ʾapnԼ�������뼤����������Ĳ���*/
    ESM_OM_ERRLOG_CAUSE_OTHERS
};
typedef VOS_UINT16  ESM_OM_ERRLOG_ID_ENUM_UINT16;

/*****************************************************************************
 �ṹ����   :EMM_OM_ERRLOG_ID_ENUM
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   :EMM���ԭ��ֵ
*****************************************************************************/
enum EMM_OM_ERRLOG_ID_ENUM
{
    EMM_OM_ERRLOG_CN_CAUSE_NULL                = 0,                         /* ��ԭ��ֵ*/
    EMM_OM_ERRLOG_CN_CAUSE_IMSI_UNKNOWN_IN_HSS = LNAS_OM_ERRLOG_ID_EMM_REJ_CN_CAUSE,  /*����ܾ��� ��ʾIMSI��HSS���Ҳ���*/
    EMM_OM_ERRLOG_CN_CAUSE_ILLEGAL_UE,                                      /* ����ܾ�,��ʾ�Ƿ�UE*/
    EMM_OM_ERRLOG_CN_CAUSE_IMEI_NOT_ACCEPTED,                               /* ����ܾ�,��ʾIMEI��������*/
    EMM_OM_ERRLOG_CN_CAUSE_ILLEGAL_ME,                                      /* ����ܾ�,��ʾ�Ƿ�ME*/
    EMM_OM_ERRLOG_CN_CAUSE_EPS_SERV_NOT_ALLOW,                              /* ����ܾ�,��ʾEPSҵ������*/
    EMM_OM_ERRLOG_CN_CAUSE_EPS_SERV_AND_NON_EPS_SERV_NOT_ALLOW,             /* ����ܾ�,��ʾEPS�ͷ�EPSҵ������*/
    EMM_OM_ERRLOG_CN_CAUSE_UE_ID_NOT_DERIVED,                               /* ����ܾ�,��ʾUE ID����ʶ��*/
    EMM_OM_ERRLOG_CN_CAUSE_IMPLICIT_DETACHED,                               /* ����ܾ�,��ʾ��ʽDETTACH*/
    EMM_OM_ERRLOG_CN_CAUSE_PLMN_NOT_ALLOW,                                  /* ����ܾ�,��ʾPLMN������*/
    EMM_OM_ERRLOG_CN_CAUSE_TA_NOT_ALLOW,                                    /* ����ܾ�,��ʾ��ǰTA������*/
    EMM_OM_ERRLOG_CN_CAUSE_ROAM_NOT_ALLOW,                                  /* ����ܾ�,��ʾ��ǰTA�в�������*/
    EMM_OM_ERRLOG_CN_CAUSE_EPS_SERV_NOT_ALLOW_IN_PLMN,                      /* ����ܾ�,��ʾ��ǰPLMN��EPSҵ������*/
    EMM_OM_ERRLOG_CN_CAUSE_NO_SUITABL_CELL,                                 /* ����ܾ�,��ʾ��ǰTA��û�п��õ�С��*/
    EMM_OM_ERRLOG_CN_CAUSE_MSC_UNREACHABLE,                                 /* ����ܾ�,��ʾ��ǰMSC���ɴ�*/
    EMM_OM_ERRLOG_CN_CAUSE_NETWORK_FAILURE,                                 /* ����ܾ�,��ʾ��ǰ�������*/
    EMM_OM_ERRLOG_CN_CAUSE_CS_NOT_AVAIL,                                    /* ����ܾ�,��ʾCS������*/
    EMM_OM_ERRLOG_CN_CAUSE_ESM_FAILURE,                                     /* ����ܾ�,��ʾESM����*/
    EMM_OM_ERRLOG_CN_CAUSE_MAC_FAILURE,                                     /* ����ܾ�,��ʾMAC����*/
    EMM_OM_ERRLOG_CN_CAUSE_SYNCH_FAILURE,                                   /* ����ܾ�,��ʾSYNCH����*/
    EMM_OM_ERRLOG_CN_CAUSE_PROCEDURE_CONGESTION,                            /* ����ܾ�,��ʾ����ӵ��*/
    EMM_OM_ERRLOG_CN_CAUSE_UE_SECU_CAP_MISMATCH,                            /* ����ܾ�,��ʾ��ȫ������ƥ��*/
    EMM_OM_ERRLOG_CN_CAUSE_SECU_MODE_REJECTED_UNSPECIFIED,                  /* ����ܾ�,��ʾ��ȫģʽ�ܾ�δָ��*/
    EMM_OM_ERRLOG_CN_CAUSE_NOT_AUTHORIZED_FOR_THIS_CSG,                     /* ����ܾ�,��ʾ��ǰ�û�û��CSG��Ȩ*/
    EMM_OM_ERRLOG_CN_CAUSE_REQUESTED_SER_OPTION_NOT_AUTHORIZED_IN_PLMN,     /* ����ܾ�,��ʾ�������δ��Ȩ�����PLMN*/
    EMM_OM_ERRLOG_CN_CAUSE_CS_FALLBACK_CALL_EST_NOT_ALLOWED,                /* ����ܾ�,��ʾCSFB����������*/
    EMM_OM_ERRLOG_CN_CAUSE_CS_DOMAIN_TMP_NOT_ALLOWED,                       /* ����ܾ�,��ʾCS DOMAIN ��ʱ������ʹ��*/
    EMM_OM_ERRLOG_CN_CAUSE_NO_EPS_BEARER_CONTEXT_ACTIVATED,                 /* ����ܾ�,��ʾû�г��������ļ���*/
    EMM_OM_ERRLOG_CN_CAUSE_SERVER_NETWORK_FAILURE,                          /* ����ܾ�,��ʾ�����������*/
    EMM_OM_ERRLOG_CN_CAUSE_SEMANTICALLY_INCORRECT_MSG,                      /* ����ܾ�,��ʾ��Ϣ�﷨����ȷ*/
    EMM_OM_ERRLOG_CN_CAUSE_INVALID_MANDATORY_INFORMATION,                   /* ����ܾ�,��ʾ��ѡ��Ԫ�Ƿ�*/
    EMM_OM_ERRLOG_CN_CAUSE_MSG_TYPE_NON_EXIST_OR_IMPLEMENT,                 /* ����ܾ�,��ʾ�����ڻ�֧�ֵ���Ϣ*/
    EMM_OM_ERRLOG_CN_CAUSE_INFO_ELEMENT_NON_EXIST_OR_NOT_IMPLEMENT,         /* ����ܾ�,��ʾ��Ϣ��Ԫ�����ڻ�֧��*/
    EMM_OM_ERRLOG_CN_CAUSE_MSG_TYPE_NOT_COMPATIBLE,                         /* ����ܾ�,��ʾ��Ϣ���Ͳ�����*/
    EMM_OM_ERRLOG_CN_CAUSE_CONDITIONAL_IE_ERROR,                            /* ����ܾ�,��ʾCONDITIONAL_IE����*/
    EMM_OM_ERRLOG_CN_CAUSE_MSG_NOT_COMPATIBLE,                              /* ����ܾ�,��ʾMSG������*/
    EMM_OM_ERRLOG_CN_CAUSE_PROTOCOL_ERROR,                                  /* ����ܾ�����ʾЭ�����*/
    EMM_OM_ERRLOG_CN_CAUSE_OTHERS                                           /* ����������ԭ��ܾ�*/
};
typedef VOS_UINT16  EMM_OM_ERRLOG_CN_REJ_ENUM_UINT16;
typedef VOS_UINT16  EMM_OM_ERRLOG_CN_CAUSE_ENUM_UINT16;


/*****************************************************************************
 ö����    : LNAS_OM_ERRLOG_ALM_ID_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : LNAS�ϱ���OMģ�������log��ALM ID����
*****************************************************************************/
enum LNAS_OM_ERRLOG_ALM_ID_ENUM
{
    LNAS_OM_ERRLOG_ALM_ID_ATTACH_FAIL           = 1,         /* attachʧ��*/
    LNAS_OM_ERRLOG_ALM_ID_TAU_FAIL              = 2,         /* TAUʧ�� */
    LNAS_OM_ERRLOG_ALM_ID_DETACH_FAIL           = 3,         /* DETACHʧ�� */
    LNAS_OM_ERRLOG_ALM_ID_NOR_SERVICE_FAIL      = 4,         /* ��ͨSERVICEʧ�� */
    LNAS_OM_ERRLOG_ALM_ID_EXT_SERVICE_FAIL      = 5,         /* ��չSERVICEʧ��*/
    LNAS_OM_ERRLOG_ALM_ID_PAGING_FAIL           = 6,         /* PAGING���̵��µĶ�����Ŀǰֻ�漰IMSI PAGING�ĳ��� */
    LNAS_OM_ERRLOG_ALM_ID_RAT_FAIL              = 7,         /* ��ϵͳ���µĶ�����Ŀǰֻ�漰W2L��ϵͳ��Ϣ��ʱ���µĶ�������*/
    LNAS_OM_ERRLOG_ALM_ID_ESM_PDN_CONN_FAIL     = 8,         /* PDN CONN REJ����ʧ��*/
    LNAS_OM_ERRLOG_ALM_ID_ESM_PDN_DISCONN_FAIL  = 9,         /* PDN DISCONN REJ����ʧ��*/
    LNAS_OM_ERRLOG_ALM_ID_ESM_RES_MOD_FAIL      = 10,        /* ��Դ�޸�����ʧ��*/
    LNAS_OM_ERRLOG_ALM_ID_ESM_RES_ALLOC_FAIL    = 11,        /* ��Դ��������ʧ��*/
    LNAS_OM_ERRLOG_ALM_ID_OVERFLOW_FAIL         = 12,        /* ����buffer�������*/

    LNAS_OM_ERRLOG_ALM_ID_BUTT
};
typedef VOS_UINT16  LNAS_OM_ERRLOG_ALM_ID_ENUM_UINT16;

/*****************************************************************************
 ö����    : LMM_ERR_LOG_ATTACH_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : UE������ATTACH TYPE
*****************************************************************************/
enum LMM_ERR_LOG_ATTACH_TYPE_ENUM
{
    EMM_ERR_LOG_ATT_TYPE_EPS_ONLY                = 1, /* EPSע�� */
    EMM_ERR_LOG_ATT_TYPE_COMBINED_EPS_IMSI       = 2, /* ����ע�� */
    EMM_ERR_LOG_ATT_TYPE_EPS_EMERGENCY           = 6, /* ����ע�� */
    EMM_ERR_LOG_ATT_TYPE_BUTT
};
typedef VOS_UINT16 EMM_ERR_LOG_ATTACH_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : EMM_ERR_LOG_TAU_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : UE������TAU����
*****************************************************************************/
enum EMM_ERR_LOG_TAU_TYPE_ENUM
{
    EMM_ERR_LOG_TA_UPDATING                     = 1,  /*PS UPDATE*/
    EMM_ERR_LOG_COMBINED_TA_LA_UPDATING         = 2,  /*����TA-LA UPDATE*/
    EMM_ERR_LOG_COMBINED_TA_LA_WITH_IMSI        = 3,  /*����TA-LA UPDATE WITH IMSI*/
    EMM_ERR_LOG_PS_PERIODIC_UPDATING            = 4,  /*PS �����Ը���*/
    EMM_ERR_LOG_CS_PS_PERIODIC_UPDATING         = 5,  /*PS ���ϵ������Ը���*/
    EMM_ERR_LOG_TAU_TYPE_BUTT
};
typedef VOS_UINT16 EMM_ERR_LOG_TAU_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : EMM_ERR_LOG_MT_DETACH_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : ���ഥ����DETACH����
*****************************************************************************/
enum EMM_ERR_LOG_MT_DETACH_TYPE_ENUM
{
    EMM_ERR_LOG_MT_DET_REATTACH_REQUIRED            = 1, /*REATTACH ��Ҫ*/
    EMM_ERR_LOG_MT_DET_REATTACH_NOT_REQUIRED        = 2, /*REATTACH ����Ҫ*/
    EMM_ERR_LOG_MT_DET_IMSI                         = 3, /*IMSI DETACH*/
    EMM_ERR_LOG_MT_DETACH_TYPE_BUTT
};
typedef VOS_UINT16 EMM_ERR_LOG_MT_DETACH_TYPE_ENUM_UINT16;

/*****************************************************************************
 �ṹ����   :EMM_OM_LMM_CSFB_FAIL_CAUSE_ENUM
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   :��ʾcsfb����ʧ��ԭ��
*****************************************************************************/
enum   EMM_OM_LMM_CSFB_FAIL_CAUSE_ENUM
{
    EMM_OM_LMM_CSFB_FAIL_CAUSE_NULL                     = 0,   /* ��ԭ��ֵ                                  */
    EMM_OM_LMM_CSFB_FAIL_CAUSE_RRC_EST_FAIL             = 1,   /* EXT SERVICE������RRC����ʧ��              */
    EMM_OM_LMM_CSFB_FAIL_CAUSE_RRC_EST_ACCESS_BAR       = 2,   /* EXT SERVICE������RRC���뱻BAR             */
    EMM_OM_LMM_CSFB_FAIL_CAUSE_RRC_REL_OTHER            = 3,   /* EXT SERVICE������RRC�����ͷţ�ԭ��ΪOTHER */
    EMM_OM_LMM_CSFB_FAIL_CAUSE_EXT3417_EXP              = 4,   /* EXT T3417��ʱ����ʱ                       */
    EMM_OM_LMM_CSFB_FAIL_CAUSE_DELAY_TIMER_EXP          = 5,   /* CSFB��ʱ��ʱ����ʱ                        */
    EMM_OM_LMM_CSFB_FAIL_CAUSE_CN_REJ                   = 6,   /* EXT SERVICE �������ܾ�                  */

    EMM_OM_LMM_CSFB_FAIL_CAUSE_BUTT
};
typedef  VOS_UINT8 EMM_OM_LMM_CSFB_FAIL_CAUSE_ENUM_UINT8;

/*****************************************************************************
 �ṹ����   :OM_LNAS_MSG_ID_ENUM_UINT32
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   :Om��LNAS������Ϣ
*****************************************************************************/
enum   OM_LNAS_MSG_ID_ENUM
{
    /* OM����LNAS��ԭ�� */
    ID_OM_LNAS_ERR_LOG_CTRL_IND                = (0x9001),   /* _H2ASN_MsgChoice LNAS_OM_ERROR_LOG_CTRL_IND_STRU */
    ID_OM_LNAS_ERR_LOG_REPORT_REQ              = (0x9002),   /* _H2ASN_MsgChoice LNAS_OM_ERR_LOG_REPORT_REQ_STRU */

    /*LNAS ����OM��ԭ��*/
    ID_LNAS_OM_ERR_LOG_REPORT_CNF              = (0x9003),   /* _H2ASN_MsgChoice LNAS_OM_ERR_LOG_REPORT_CNF_STRU */
};
typedef VOS_UINT32   OM_LNAS_MSG_ID_ENUM_UINT32;

/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
   5 STRUCT
*****************************************************************************/
/*****************************************************************************
 �ṹ����   : LNAS_ERR_INFO_OVERFLOW_COUNT_EVENT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : LNAS ����buffer���������OM�ϱ���ERRLOG�¼��ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulMsgModuleId;
    VOS_UINT16                          usModemId;
    VOS_UINT16                          usAlmId;
    VOS_UINT16                          usAlmLevel;
    VOS_UINT16                          usAlmType;
    VOS_UINT32                          ulAlmLowSlice;
    VOS_UINT32                          ulAlmHighSlice;
    VOS_UINT32                          ulAlmLength;
}LNAS_OM_ERR_LOG_HEADER_STRU;

/*****************************************************************************
 �ṹ����   : LNAS_ERR_INFO_OVERFLOW_COUNT_EVENT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : LNAS ����buffer���������OM�ϱ���ERRLOG�¼��ṹ
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU                     stHeader;           /*��Ϣͷ*/

    VOS_UINT32                                      ulOverflowCount;    /*�������*/
}LNAS_ERR_INFO_OVERFLOW_COUNT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   : EMM_OM_ERRLOG_ATTACH_CN_REJ_RESULT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : ATTACH CN�ܾ�ʱ��Ҫ�ϱ�����Ϣ
*****************************************************************************/
typedef struct
{
    EMM_OM_ERRLOG_CN_REJ_ENUM_UINT16        enCnRejCause;    /*ATTACH�ܾ�ԭ��ֵ*/
    EMM_ERR_LOG_ATTACH_TYPE_ENUM_UINT16     enReqType;       /*ATTACH����ʱ������ */
}EMM_OM_ERRLOG_ATTACH_CN_REJ_RESULT_STRU;

/*****************************************************************************
 �ṹ����   : LMM_ERR_INFO_ATTACH_RESULT_EVENT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : LNAS ATTACH������OM�ϱ���ERRLOG�¼��ṹ
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU                     stHeader;       /*��Ϣͷ*/

    EMM_OM_ERRLOG_TYPE_ENUM_UINT16                  enErrType;      /*��������*/
    VOS_UINT16                                      usRsv;

    EMM_OM_ERRLOG_ATTACH_CN_REJ_RESULT_STRU         stAttachCnRej;  /*ATTACH CN�ܾ���ؽṹ*/
}EMM_ERR_INFO_ATTACH_RESULT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   : EMM_OM_ERRLOG_TAU_CN_REJ_RESULT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : TAU CN�ܾ�ʱ��Ҫ�ϱ�����Ϣ
*****************************************************************************/
typedef struct
{
    EMM_OM_ERRLOG_CN_REJ_ENUM_UINT16        enCnRejCause;    /*TAU�ܾ�ԭ��ֵ*/
    EMM_ERR_LOG_TAU_TYPE_ENUM_UINT16        enReqType;       /*TAU����ҵ��ʱ������*/
}EMM_OM_ERRLOG_TAU_CN_REJ_RESULT_STRU;

/*****************************************************************************
 �ṹ����   : LMM_ERR_INFO_TAU_RESULT_EVENT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : LNAS TAU������OM�ϱ���ERRLOG�¼��ṹ
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU                     stHeader;       /*��Ϣͷ*/

    EMM_OM_ERRLOG_TYPE_ENUM_UINT16                  enErrType;      /*��������*/
    VOS_UINT16                                      usRsv;

    EMM_OM_ERRLOG_TAU_CN_REJ_RESULT_STRU            stTauCnRej;     /*TAU CN�ܾ���ؽṹ*/
}EMM_ERR_INFO_TAU_RESULT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   : EMM_ERR_INFO_MT_DETACH_RESULT_EVENT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : LNAS MT DETACH������OM�ϱ���ERRLOG�¼��ṹ
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU             stHeader;           /*��Ϣͷ*/

    EMM_OM_ERRLOG_CN_CAUSE_ENUM_UINT16      enCnDetCause;       /*MT DETACH���ܴ�ԭ��ֵ��������������ó���Чֵ*/
    EMM_ERR_LOG_MT_DETACH_TYPE_ENUM_UINT16  enCnDetReqType;     /*���ഥ����DETACH����*/
}EMM_ERR_INFO_MT_DETACH_RESULT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   : EMM_OM_ERRLOG_NOR_SERVICE_CN_REJ_RESULT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : NORMAL SERVICE��ص�����ʧ���ϱ��ṹ(��ͨ��������)
*****************************************************************************/
typedef struct
{
    EMM_OM_ERRLOG_CN_REJ_ENUM_UINT16        enCnRejCause;    /*SERVICE�ܾ�ԭ��ֵ*/
    VOS_UINT16                              usRsv;
}EMM_OM_ERRLOG_NOR_SERVICE_CN_REJ_RESULT_STRU;

/*****************************************************************************
 �ṹ����   : EMM_ERR_INFO_NOR_SERVICE_RESULT_EVENT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : NORMAL SERVICE��ص�����ʧ���ϱ��ṹ(��ͨ����ҵ������)
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU                     stHeader;           /*��Ϣͷ*/

    EMM_OM_ERRLOG_TYPE_ENUM_UINT16                  enErrType;          /*��������*/
    VOS_UINT16                                      usRsv;

    EMM_OM_ERRLOG_NOR_SERVICE_CN_REJ_RESULT_STRU    stNorServiceCnRej;  /*��ͨService CN�ܾ���ؽṹ*/
}EMM_ERR_INFO_NOR_SERVICE_RESULT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   : EMM_ERR_INFO_EXT_SERVICE_RESULT_EVENT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : EXT-SERVICE��ص�����ʧ���ϱ��ṹ(CSFB����)
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU                     stHeader;           /*��Ϣͷ*/

    EMM_OM_LMM_CSFB_FAIL_CAUSE_ENUM_UINT8           enCsfbFailCause;    /* CSFBʧ��ԭ��*/
    VOS_UINT8                                       ucRcv;
    EMM_OM_ERRLOG_CN_REJ_ENUM_UINT16                enCnRejCause;       /* ���ܻᵼ�¶�����ԭ��ֵ*/
}EMM_ERR_INFO_EXT_SERVICE_RESULT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   : LMM_ERR_INFO_PAGING_RESULT_EVENT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : LNAS PAGING������OM�ϱ���ERRLOG�¼��ṹ��Ŀǰֻ��עPS IMSI PAGING
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU             stHeader;           /*��Ϣͷ*/

    EMM_OM_ERRLOG_PAGING_ENUM_UINT16        enPagingProcess;    /*��Ӧĳһ�����PAGING����*/
    VOS_UINT16                              usRsv;
}EMM_ERR_INFO_PAGING_RESULT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   : LMM_ERR_INFO_RAT_RESULT_EVENT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : LNAS RAT������OM�ϱ���ERRLOG�¼��ṹ��Ŀǰֻ���ĵ�ϵͳ��Ϣ��ʱ�ĳ���
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU             stHeader;       /*��Ϣͷ*/

    EMM_OM_ERRLOG_RAT_ENUM_UINT16           enRatProcess;   /*��Ӧĳһ�������ϵͳ����*/
    VOS_UINT16                              usRsv;
}EMM_ERR_INFO_RAT_RESULT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   :ESM_OM_ERRLOG_PDN_CONN_REJ_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : PDN CONN REJ�ϱ��ṹ
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU             stHeader;       /*��Ϣͷ*/

    ESM_OM_ERRLOG_ID_ENUM_UINT16            enFailCause;    /*ESM��ؾܾ�ԭ��ֵ*/
    VOS_UINT16                              usRsv;
} ESM_ERR_INFO_PDN_CONN_REJ_RESULT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   :ESM_OM_ERRLOG_PDN_DISCONN_REJ_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : PDN DISCONN REJ�ϱ��ṹ
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU             stHeader;       /*��Ϣͷ*/

    ESM_OM_ERRLOG_ID_ENUM_UINT16            enFailCause;    /*ESM��ؾܾ�ԭ��ֵ*/
    VOS_UINT16                              usRsv;
} ESM_ERR_INFO_PDN_DISCONN_REJ_RESULT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   :ESM_ERR_INFO_RES_MOD_REJ_RESULT_EVENT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : RES MOD REJ�ϱ��ṹ
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU             stHeader;       /*��Ϣͷ*/

    ESM_OM_ERRLOG_ID_ENUM_UINT16            enFailCause;    /*ESM��ؾܾ�ԭ��ֵ*/
    VOS_UINT16                              usRsv;
} ESM_ERR_INFO_RES_MOD_REJ_RESULT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   :ESM_ERR_INFO_RES_ALLOC_REJ_RESULT_EVENT_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : RES ALLOC REJ�ϱ��ṹ
*****************************************************************************/
typedef struct
{
    LNAS_OM_ERR_LOG_HEADER_STRU             stHeader;       /*��Ϣͷ*/

    ESM_OM_ERRLOG_ID_ENUM_UINT16            enFailCause;    /*ESM��ؾܾ�ԭ��ֵ*/
    VOS_UINT16                              usRsv;
} ESM_ERR_INFO_RES_ALLOC_REJ_RESULT_EVENT_STRU;

/*****************************************************************************
 �ṹ����   : LNAS_OM_ERR_LOG_REPORT_CNF_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : LNAS��OM�ظ�ERRLOGӦ�����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                     /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;     /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgType;
    VOS_UINT32                          ulMsgSN;
    VOS_UINT32                          ulRptlen;      /* �������ݳ���,���ulRptlenΪ0,aucContent���ݳ���ҲΪ0 */
    VOS_UINT8                           aucContent[4]; /* �������� */
    /*************************************************************************
        _H2ASN_Array2String
    *************************************************************************/
} LNAS_OM_ERR_LOG_REPORT_CNF_STRU;

/*****************************************************************************
 �ṹ����   : LNAS_OM_ERROR_LOG_CTRL_IND_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : ERRLOG ������ϢIND
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                    /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;    /*_H2ASN_Skip*/
    VOS_UINT16                          usModemID;
    VOS_UINT8                           ucAlmStatus;  /* �򿪻��߹ر�ERRLOG�ϱ����� 0:close 1:open */
    VOS_UINT8                           ucAlmLevel;   /* �ϱ����� */
}LNAS_OM_ERROR_LOG_CTRL_IND_STRU;

/*****************************************************************************
 �ṹ����   : LNAS_OM_ERR_LOG_REPORT_REQ_STRU
 Э�����   :
 ASN.1 ���� :
 �ṹ˵��   : ERRLOG������Ϣ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                  /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;  /*_H2ASN_Skip*/
    VOS_UINT16                          usModemID;
    VOS_UINT8                           aucRsv[2];
}LNAS_OM_ERR_LOG_REPORT_REQ_STRU;


typedef struct
{
    OM_LNAS_MSG_ID_ENUM_UINT32          enMsgID;            /*_H2ASN_MsgChoice_Export OM_LNAS_MSG_ID_ENUM_UINT32*/
    VOS_UINT8                           aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          OM_LNAS_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}OM_LNAS_MSG_DATA;

typedef struct
{
    VOS_MSG_HEADER
    OM_LNAS_MSG_DATA                    stMsgData;
}OmLnasInterface_MSG;

/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/


/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/


/*****************************************************************************
  9 OTHERS
*****************************************************************************/










#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of LnasErrlogInterface.h */

