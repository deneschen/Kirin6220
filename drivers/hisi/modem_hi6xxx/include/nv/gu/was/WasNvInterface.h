/******************************************************************************

  Copyright(C)2008,Hisilicon Co. LTD.

 ******************************************************************************
  File Name       : WasNvInterface.h
  Description     : WasNvInterface.h header file
  History         :

******************************************************************************/

#ifndef __WASNVINTERFACE_H__
#define __WASNVINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

#include "PsTypeDef.h"

/*****************************************************************************
  2 Macro
*****************************************************************************/
#define WAS_MAX_NETWORKPARA_SIZE                (144)                           /*  NET WorkPara�ļ����Ⱥ궨�� */
#define WAS_HISTORY_PLMN_MAX_NUM                (16)                            /* �洢��NV�е����PLMN��Ϣ */
#define WAS_OPERATOR_FREQS_MAX_NUM              (24)
#define NV_ITEM_MEAS_THRESHOLD_SIZE             (40)
#define WAS_MAPWEIGHT_MAX_NUM                   (16)
#define WAS_HISTORY_PLMN_ID_BYTES               (3)
#define WAS_HISTORY_FREQS_MAX_NUM               (6)                             /* �洢��NV�е�PLMN��Ӧ��Ƶ�������� */
#define WAS_UE_ACCESS_CAPA_NUM                  (20)
#define NVIM_MAX_MCC_SIZE                       (3)
#define NVIM_MAX_MNC_SIZE                       (3)
#define NVIM_MAX_RPLMN_FDD_FREQ_NUM             (8)
#define NV_ITEM_RPLMN_INFO_SIZE                 (56)
#define NV_ITEM_NETWORKPARA_SIZE                (144)
#define NV_Item_WAS_RadioAccess_Capa_SIZE       (20)
#define NV_Item_WAS_RadioAccess_Capa_New_SIZE   (48)                            /* WAS����NV��NV_Item_WAS_RadioAccess_Capa_New */
#define NV_Item_WCDMA_PLMN_FREQ_PAIR_List_SIZE  (260)
#define NV_Item_WCDMA_OPERATOR_FREQ_List_SIZE   (56)
#define NV_ITEM_BG_THRESHOLD_SIZE               (8)
#define NV_ITEM_PDCP_LOSSLESS_SIZE              (2)
#define NV_ITEM_DYN_FREQUENCY_SIZE              (2)
#define NV_ITEM_INIT_FREQUENCY_SIZE             (2)
#define NV_ITEM_PLMN_SEARCH_THRESHOLD_SIZE      (4)
#define NV_ITEM_PLMN_SEARCH_FLOW_SIZE           (8)
#define NV_ITEM_ALL_BAND_SEARCH_PARA_SIZE       (8)
#define NV_ITEM_BROKEN_CELL_PARA_SIZE           (4)
#define NV_ITEM_WAS_ERRORLOG_ITEM_NUM           (4)
#define NV_ITEM_WCDMA_IND_FRED_SIZE             (2)
#define NV_ITEM_FREQBANDS_LIST_SIZE             (52)
#define WAS_NV_MEAS_THRESHOLD_HALF_THRHLD_SIZE  (NV_ITEM_MEAS_THRESHOLD_SIZE/2)
#define WAS_NV_MEAS_THRESHOLD_RESERVE_SIZE      (WAS_NV_MEAS_THRESHOLD_HALF_THRHLD_SIZE-4)
#define NV_ITEM_WAS_ERRORLOG_CSHO_LEN_SIZE      (2)
#define WAS_NV_PTL_VER_R3                       (0)                             /* WAS_PTL_VER_R3 */
#define WAS_NV_PTL_VER_R4                       (1)                             /* WAS_PTL_VER_R4 */
#define WAS_NV_PTL_VER_R5                       (2)                             /* WAS_PTL_VER_R5 */
#define WAS_NV_PTL_VER_R6                       (3)                             /* WAS_PTL_VER_R6 */
#define WAS_NV_PTL_VER_R7                       (4)                             /* WAS_PTL_VER_R7 */
#define WAS_NV_PTL_VER_R8                       (5)                             /* WAS_PTL_VER_R8 */
#define WAS_NV_PTL_VER_R9                       (6)                             /* WAS_PTL_VER_R9 */

#define WAS_INVALID_MNC                         (0xffffffff)
#define WAS_MAX_CSFB_MCC_BAND_NUM               (80)
#define WAS_CSFB_MAX_DETECT_CELL_NUM            (3)                              /* С������ʱ����ϱ��ļ��С������ */





/*****************************************************************************
  3 Massage Declare
*****************************************************************************/


/*****************************************************************************
  4 Enum
*****************************************************************************/


/*****************************************************************************
  5 STRUCT
*****************************************************************************/
/*****************************************************************************
*                                                                            *
*                           ����������Ϣ�ṹ                                 *
*                                                                            *
******************************************************************************/

/*****************************************************************************
 �ṹ��    : WAS_NVIM_NETPARA_STRU
 �ṹ˵��  : NET PARA��Ϣ�ṹ                       ID:8246 en_NV_Item_NetWorkPara
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               aucFileContent[WAS_MAX_NETWORKPARA_SIZE];   /* File���� */
}WAS_NVIM_NETPARA_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_MEAS_THRESHOLD_STRU
 �ṹ˵��  : ��NVIM�ж�����MeasThreshold����        ID:8263 en_NV_Item_Meas_Threshold
*****************************************************************************/
typedef struct
{
    VOS_INT16                               sMeasRptRscpThreshold;              /* 1a/1c�¼��������RSCP����    */
    VOS_INT16                               sMeasRptEcn0Threshold;              /* 1a/1c�¼��������ECN0����    */
    VOS_INT16                               sCellSrchRscpThreshold;             /* С���������RSCP����         */
    VOS_INT16                               sCellSrchEcn0Threshold;             /* С���������ECN0����         */
    VOS_INT16                               asReserve[WAS_NV_MEAS_THRESHOLD_RESERVE_SIZE];     /* �����ֶ� */
}WAS_NVIM_MEAS_THRESHOLD_STRU;

typedef struct
{
    VOS_UINT8                               aucPlmnId[WAS_HISTORY_PLMN_ID_BYTES];
    VOS_UINT8                               ucFreqCnt;
    VOS_UINT16                              ausFreq[WAS_HISTORY_FREQS_MAX_NUM];
}WAS_NVIM_PLMN_FREQ_PAIR_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_PLMN_FREQ_PAIR_LIST_STRU
 �ṹ˵��  : ��NV�ж�ȡ���������ʷPLMN�Ͷ�Ӧ��Ƶ�� ID:8284 en_NV_Item_WCDMA_PLMN_FREQ_PAIR_List
*****************************************************************************/
typedef struct
{
    VOS_UINT32                              ulPlmnCnt;
    WAS_NVIM_PLMN_FREQ_PAIR_STRU            astNvPlmnFreqPair[WAS_HISTORY_PLMN_MAX_NUM];
}WAS_NVIM_PLMN_FREQ_PAIR_LIST_STRU;

typedef struct
{
    VOS_UINT8    ucMcc[NVIM_MAX_MCC_SIZE];
    VOS_UINT8    ucMnc[NVIM_MAX_MNC_SIZE];
}NVIM_PLMN_ID_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_PLMN_FREQ_PAIR_LIST_STRU
 �ṹ˵��  : ��NV�ж�ȡ���������ʷPLMN�Ͷ�Ӧ��Ƶ�� ID:8314 en_NV_Item_Opr_Freq_List
*****************************************************************************/
typedef struct
{
    PS_BOOL_ENUM_UINT8                      enOperatorFreqListValidFlg;              /* Ƶ���б��Ƿ���Ч��־ */
    NVIM_PLMN_ID_STRU                       stPlmnId;                                /* Plmn ID */
    VOS_UINT8                               ucFreqNum;                               /* �������plmn��Ƶ����� */
    VOS_UINT16                              ausFreqInfo[WAS_OPERATOR_FREQS_MAX_NUM]; /* �������plmn��Ƶ����Ϣ */
}WAS_NVIM_OPERATOR_FREQ_LIST_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_BG_THRESHOLD_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : ��NVIM�ж����ı�����Threshold����      ID:8316 en_NV_Item_BG_Threshold
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucStatus;                           /*������ѡ��,0:������,1����,Ĭ��ֵ:1*/
    VOS_INT8                                cWCDMA_RSSI_Threshold;              /*Range:[-125,0]*/ /*WCDMA RSSI����,Ĭ��ֵ:-95*/
    VOS_INT8                                cWCDMA_Cpich_EcNo_Threshold;        /*Range:[-25,0]*/  /*WCDMA Cpich_EcNo����,Ĭ��ֵ:-11*/
    VOS_INT8                                cWCDMA_Cpich_Rscp_Threshold;        /*Range:[-125,0]*/ /*WCDMA Cpich_Rscp����,Ĭ��ֵ:-100*/
    VOS_INT8                                cGSM_RSSI_Threshold;                /*Range:[-125,0]*/ /*GSM RSSI����,Ĭ��ֵ:-95*/
    VOS_UINT8                               ucBgGsmMeasSqualOffset;             /* �����ȼ�RAT��ʱGSM������������Squal offset */
    VOS_UINT8                               ucBgGsmMeasSrxlevOffset;            /* �����ȼ�RAT��ʱGSM������������Srxlev offset */
    PS_BOOL_ENUM_UINT8                      enBgModifyDrxThresholdFlg;          /* �޸�BG��DRX���ޱ�� */
}WAS_NVIM_BG_THRESHOLD_STRU;

/*****************************************************************************
 �ṹ��    : WAS_BROKEN_CELL_STRU
 �ṹ˵��  : ���Broken Cell�Ĳ�������              ID:8341 en_NV_Item_WAS_BROKEN_CELL_PARA
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usNfail;                            /* ������Nfail��RRC_CONN_REQ�ط�,����С������Bar�б� */
    VOS_UINT16                              usTBarFailLen;                      /* С�������ֹ�б���ʱ�䣬��λ:�� */
} WAS_BROKEN_CELL_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_UE_FEATURE_CTRL
 �ṹ˵��  : �洢��NVIM�����V3����������Ϣ         ID:8472 en_NV_Item_Was_UeFeature_Ctrl
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucIntegAlg;                         /* Ĭ��ֵΪ6,֧��UIA1&UIA2 */
    VOS_UINT8                               ucCipherAlg;                        /* Ĭ��ֵΪ7,֧��UEA1&UEA2 */
    VOS_UINT8                               ucWasFeatrue;                       /* Ĭ��ֵΪ0,bitλ���ο��Ƹ����ƶ�����˫DRX�����Ƿ�֧��*/
	PS_BOOL_ENUM_UINT8                      enEPchCbsSupport;                   /* �Ƿ�֧��Epch�½���Cbs */
}WAS_NVIM_UE_FEATURE_CTRL;

/*****************************************************************************
 �ṹ��    : WAS_WEAK_SIGNAL_ENERGY_THRESHOLD_STRU
 �ṹ˵��  : Errorlog���źŵ�����                   ID:8499 en_NV_Item_WAS_Errorlog_Energy_Threshold
*****************************************************************************/
typedef struct
{
    VOS_INT16                               sRscpThreshold;
    VOS_INT16                               sECN0Threshold;
}WAS_WEAK_SIGNAL_ENERGY_THRESHOLD_STRU;

/*****************************************************************************
 ö����    : WAS_TX_RX_FREQ_SEPARAT_ENUM_UINT8
 Э�����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/
enum WAS_TX_RX_FREQ_SEPARAT_ENUM
{
    WAS_TX_RX_FREQ_SEPARAT_DEFAULT_TX_RX_SEPARATION = 0,
    WAS_TX_RX_FREQ_SEPARAT_SPARE2,
    WAS_TX_RX_FREQ_SEPARAT_SPARE1,
    WAS_TX_RX_FREQ_SEPARAT_BUTT
} ;
typedef VOS_UINT8 WAS_TX_RX_FREQ_SEPARAT_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : WAS_RF_CAPA_STRU
 Э�����  : 10.3.3.33 RF capability FDD
 ASN.1���� :
 �ṹ˵��  : RF������Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucPowerClass;                       /* UE���ʼ���                               */
    WAS_TX_RX_FREQ_SEPARAT_ENUM_UINT8       enTxRxFreqSeparate;                 /* Tx/Rx Ƶ������                           */
    VOS_UINT8                               aucReserve1[2];                     /* 4�ֽڶ��룬���� */
}WAS_RF_CAPA_STRU;


/*****************************************************************************
 ö����    : WAS_DL_SIMUL_HS_DSCH_CFG_ENUM_UINT8
 Э�����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/
enum  WAS_DL_SIMUL_HS_DSCH_CFG_ENUM
{
    WAS_DL_SIMUL_HS_DSCH_CFG_KBPS32 = 0,
    WAS_DL_SIMUL_HS_DSCH_CFG_KBPS64,
    WAS_DL_SIMUL_HS_DSCH_CFG_KBPS128,
    WAS_DL_SIMUL_HS_DSCH_CFG_KBPS384,
    WAS_DL_SIMUL_HS_DSCH_CFG_BUTT
};
typedef VOS_UINT8 WAS_DL_SIMUL_HS_DSCH_CFG_ENUM_UINT8;

/*****************************************************************************
 ö����    : WAS_PTL_VER_TYPE_ENUM_UINT8
 Э�����  : 10.2.39    RRC CONNECTION REQUEST
 ASN.1���� : AccessStratumReleaseIndicator
 ö��˵��  : Э��汾
             Absence of the IE implies R3.
             The IE also indicates the release of the RRC transfer syntax
             supported by the UE 13 spare values are needed
*****************************************************************************/
enum WAS_PTL_VER_TYPE_ENUM
{
    WAS_PTL_VER_ENUM_R3                 = WAS_NV_PTL_VER_R3,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R3 = 0 */
    WAS_PTL_VER_ENUM_R4                 = WAS_NV_PTL_VER_R4,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R4 = 1 */
    WAS_PTL_VER_ENUM_R5                 = WAS_NV_PTL_VER_R5,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R5 = 2 */
    WAS_PTL_VER_ENUM_R6                 = WAS_NV_PTL_VER_R6,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R6 = 3 */
    WAS_PTL_VER_ENUM_R7                 = WAS_NV_PTL_VER_R7,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R7 = 4 */
    WAS_PTL_VER_ENUM_R8                 = WAS_NV_PTL_VER_R8,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R8 = 5 */
    WAS_PTL_VER_ENUM_R9                 = WAS_NV_PTL_VER_R9,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R9 = 6 */
    WAS_PTL_VER_ENUM_BUTT
};
typedef VOS_UINT8 WAS_PTL_VER_TYPE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_UE_CAPA_STRU
 �ṹ˵��  : �洢��NVIM�е�UE������Ϣ               ID:9008 en_NV_Item_WAS_RadioAccess_Capa_New
*****************************************************************************/
typedef struct
{
    VOS_UINT32                              ulHspaStatus;                       /* 0��ʾδ����,��ôDPA��UPA��֧��;1��ʾ���� */

    WAS_RF_CAPA_STRU                        stRfCapa;                           /* RF ������Ϣ                                  */

    PS_BOOL_ENUM_UINT8                      enSupportPwrBoosting;               /* 16QAM������أ��Ƿ�֧��E-DPCCH Power Boosting*/
    PS_BOOL_ENUM_UINT8                      enSf4Support;                       /* �Ƿ�֧��ul dpcch ʹ�� slotFormat4 */

    WAS_DL_SIMUL_HS_DSCH_CFG_ENUM_UINT8     enDlSimulHsDschCfg;                 /* ENUMERATED  OPTIONAL                         */
    WAS_PTL_VER_TYPE_ENUM_UINT8             enAsRelIndicator;                   /* Access Stratum Release Indicator             */

    PS_BOOL_ENUM_UINT8                      enHSDSCHSupport;                    /* �Ƿ�֧��enHSDSCHSupport�ı�־                */
    VOS_UINT8                               ucHSDSCHPhyCategory;                /* ֧��HS-DSCH����������ͱ�־                  */

    PS_BOOL_ENUM_UINT8                      enMacEhsSupport;
    VOS_UINT8                               ucHSDSCHPhyCategoryExt;
    PS_BOOL_ENUM_UINT8                      enMultiCellSupport;                 /* �Ƿ�֧�� Multi cell support,���֧��MultiCell,Ex2���� */
    VOS_UINT8                               ucHSDSCHPhyCategoryExt2;            /* HS-DSCH physical layer category extension 2 */

    PS_BOOL_ENUM_UINT8                      enCellSpecTxDiversityForDc;         /*  This IE is optionally present if Dual-Cell HSDPA is supported. Otherwise it is not needed.
                                                                                    The IE is not needed in the INTER RAT HANDOVER INFO message. Otherwise, it is optional*/
    PS_BOOL_ENUM_UINT8                      enEFDPCHSupport;                    /* �Ƿ�֧��E-FDPCH�ı�־,FDPCH֧��ʱ��NV����Ч */
    PS_BOOL_ENUM_UINT8                      enEDCHSupport;                      /* �Ƿ�֧��EDCH�ı�־                           */
    VOS_UINT8                               ucEDCHPhyCategory;                  /* ֧��UPA�ĵȼ�                                */
    PS_BOOL_ENUM_UINT8                      enSuppUl16QAM;                      /* �Ƿ�֧������16QAM����֧��ʱucEDCHPhyCategoryExt����Ч */
    VOS_UINT8                               ucEDCHPhyCategoryExt;               /* ���е��ز�֧��16QAMʱ����д7 */
    PS_BOOL_ENUM_UINT8                      enSuppEDpdchInterpolationFormula;   /* 16QAM������أ��Ƿ�֧��E-DPDCH power interpolation formula */
    PS_BOOL_ENUM_UINT8                      enSuppHsdpaInFach;                  /* ֧��CELL_FACH��HS-DSCH�Ľ��� */
    PS_BOOL_ENUM_UINT8                      enSuppHsdpaInPch;                   /* ֧��CELL_PCH��URA_PCH��HS-DSCH�Ľ��� */

    PS_BOOL_ENUM_UINT8                      enMacIsSupport;                     /* �Ƿ�֧��MAC_I/MAC_Is */

    PS_BOOL_ENUM_UINT8                      enFDPCHSupport;                     /* �Ƿ�֧��FDPCH�ı�־                          */

    PS_BOOL_ENUM_UINT8                      enHsscchLessSupport;                /* �Ƿ�֧�� hsscchlessHsdschOperation           */
    PS_BOOL_ENUM_UINT8                      enUlDpcchDtxSupport;                /* �Ƿ�֧�� discontinuousDpcchTransmission      */

    PS_BOOL_ENUM_UINT8                      enAdjFreqMeasWithoutCmprMode;       /* �Ƿ�֧�� Adjacent Frequency measurements without compressed mode */

    PS_BOOL_ENUM_UINT8                      enMimoSingleStreamStrict;           /* �Ƿ�����ֻ��ʹ�õ���MIMO */
    PS_BOOL_ENUM_UINT8                      enMimoWithDlTxDiversity;            /* R9���ԣ���MIMO����ʱ�����п����ŵ��Ƿ�����ʹ�÷ּ� */

    /* V7r1 ˫ģ����NV�� LTE���� */
    PS_BOOL_ENUM_UINT8                      enSptAbsPriBasedReselInUtra;        /* ֧��UTRA�е����ȼ���ѡ��Ĭ��Ϊ0��1Ϊ֧�֣�0Ϊ��֧�� */

    VOS_UINT8                               ucHSDSCHPhyCategoryExt3;            /* HS-DSCH physical layer category extension 3 */
    PS_BOOL_ENUM_UINT8                      enDcMimoSupport;                    /* �Ƿ�֧��DC+MIMO */
    PS_BOOL_ENUM_UINT8                      enSuppCommEDCH;                     /* E-RACH�������� */

    PS_BOOL_ENUM_UINT8                      enDcUpaSupport;                     /* �Ƿ�֧��DC UPA�ı�־ */
    VOS_UINT8                               ucEDCHPhyCategoryExt2;              /* EDCH  category extension 2*/
    PS_BOOL_ENUM_UINT8                      enEdpdchGainFactorFlg;              /* E-DPDCH���ʻ�������ʹ�ܱ�־λ */
    PS_BOOL_ENUM_UINT8                      enHo2EutranUnSupportFlg;            /* �Ƿ�֧�ֵ�L��HO */
    PS_BOOL_ENUM_UINT8                      enEutranMeasUnSupportFlg;           /* �Ƿ�֧�ֵ�����̬L�Ĳ��� */
    VOS_UINT8                               aucReserve2[5];
}WAS_NVIM_UE_CAPA_STRU;

/*****************************************************************************
 �ṹ��    : WAS_PRACH_PARA_STRU
 �ṹ˵��  : W�·����������ʱ������Ҫ�Ĳ���        ID:9023 en_NV_Item_Wcdma_Prach_Para
*****************************************************************************/
typedef struct
{
    VOS_INT8                                cInitTxPowerExt;                    /*Range:[0,20]*/ /* ��ʼ���书�ʵ��ڲ��� */
    VOS_UINT8                               ucPrbRetransMaxExt;                 /* ������뷢��������ڲ��� */
    VOS_UINT8                               aucReserve[2];
    VOS_UINT32                              ulASC0Para;                         /* �����������������㷨���� */
}WAS_PRACH_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NVIM_FASTDORM_PARA_STRU
 �ṹ˵��  : FASTDORM������ز���                   ID:9027 en_NV_Item_Fastdorm_Para
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucWasMaxSCRINumInPCH;               /* WAS�����P��DRX����<CN��DRX���ڳ�����СֵʱSCRI����ʹ���  */
    VOS_UINT8                               ucNasRetryInterval;                 /* NAS�����Retryʱ����������Ϊ��λ*/
    VOS_UINT8                               ucT323Default;                      /* �������õ�T323Ϊ0ʱʹ��NV�����õ�Ĭ��ֵ */
    VOS_UINT8                               aucReserved[1];                     /* Ԥ�� */
}NVIM_FASTDORM_PARA_STRU;

/*****************************************************************************
 �ṹ��    : WAS_CSFB_PPAC_STRU
 �ṹ˵��  : �������������Ϣ                       ID:9050 en_NV_Item_CSFB_PPAC_Para
*****************************************************************************/
typedef struct
{
    PS_BOOL_ENUM_UINT8                      enSuppPPACFlg;                      /* PPAC��־ */
    PS_BOOL_ENUM_UINT8                      enCsfbRcvAllSibFlg;                 /* CSFB�Ƿ�ȫ��ϵͳ��Ϣ��־ ,Ĭ��ֵΪ0����־��ȫ�� */
    PS_BOOL_ENUM_UINT8                      enCsfbSearchFailFastReturnFlg;      /* W��ָ��Ƶ���С������ʧ�ܺ󣬲��ٷ���ȫƵ��������������LTE */
    VOS_UINT8                               ucFrWaitGmmProcAndTimerLen;         /* CSFB���̽�����FRʱ�Ƿ�ȴ�GMM���̽�����Ǻ͵ȴ�FR��ʱ�� */
}WAS_CSFB_PPAC_STRU;

/*****************************************************************************
 �ṹ��    : WAS_3G_TO_2G_STRU
 �ṹ˵��  : 3G��2G��ѡ�Ż�NV
*****************************************************************************/
typedef struct
{
    PS_BOOL_ENUM_UINT8                      enSuppDetectCellSearchFlg;          /* ֧����������־ */
    VOS_UINT8                               ucDetectCellSearchThreshold;        /* ������������Ĭ������ֵ */
    VOS_UINT8                               ucStartDetectCellSearchCnt;         /* ��������������Ҫ����С����������ֹͣ���޵Ĵ��� */
    VOS_UINT8                               ucStopDetectCellSearchCnt;          /* ֹͣ����������Ҫ����С����������ֹͣ���޵Ĵ��� */
}WAS_3G_TO_2G_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_REPORT_CELL_SIGN_STRU
 �ṹ˵��  : С���ź�ǿ���ϱ���ʱ�����Ⱥ�RSCP�仯������ֵ   ID:9067 en_NV_Item_Report_Cell_Sign
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucPeriodTimerLen;
    VOS_UINT8                               ucRscpThreshold;
    VOS_UINT8                               ucEcn0Threshold;
    VOS_UINT8                               aucReserve1[1];
}WAS_NVIM_REPORT_CELL_SIGN_STRU;

/*****************************************************************************
 �ṹ��    : WAS_CUSTOMIZED_PARA_STRU
 �ṹ˵��  : W��������ѡ����                        ID: 9069 en_NV_Item_Was_Customized_Para
*****************************************************************************/
typedef struct
{
    /* Was_Customized_Para */
    VOS_UINT8                               ucSbmMaskSupportType;
    VOS_UINT8                               ucDchOosSearchInterRatFlg;          /* DCH�´���CUʱT314����ʱ�Ƿ�������ϵͳ���*/
    VOS_UINT8                               ucOosAllBandHistoryFreqValidFlg;    /* ��������ָ��PLMN�ѣ���ʷƵ��������ȫƵ������ʱ��������������ʷƵ�� */
    VOS_UINT8                               ucOosAllBandAddHistoryFreqCnt;      /* ��������ȫƵ������ָ��Ƶ���б���ʱ������ʷƵ��ĸ��� */
    VOS_UINT32                              ulDocomMcc;
    VOS_UINT32                              ulDocomMnc;
}WAS_CUSTOMIZED_PARA_STRU;

/*****************************************************************************
 �ṹ��    : WAS_W2L_CEll_RESEL_OFFSET_STRU
 �ṹ˵��  : W2L��ѡ�͹������NV�ṹ                ID:9124 en_NV_Item_LOW_POWER_Cell_Resel_OffSet
*****************************************************************************/
typedef struct
{
    PS_BOOL_ENUM_UINT8                      enOffsetEnableFlg;                  /* offset NVʹ�ܱ��    */
    PS_BOOL_ENUM_UINT8                      enR8BasedCellReselFlg;              /* offset NVʹ�ܱ��,enW2LR8BasedCellReselFlg���ܿ���    */
    VOS_UINT8                               aucReserve1[2];                     /* ����λ */
    VOS_UINT16                              usWRscpThresh;                      /*Range:[0,928]*/  /* W����С��RSCP���ޣ��������޲���ʹ����ѡOFFSET��ȡ����ֵ */
    VOS_UINT16                              usWEcnoThresh;                      /*Range:[0,160]*/  /* W����С��ECNO���ޣ��������޲���ʹ����ѡOFFSET��ȡ����ֵ */
    VOS_UINT16                              usEutranCellRsrpOffset;             /*Range:[0,1040]*/ /* EUTRANС��RSRP OFFSET */
    VOS_UINT16                              usEutranCellRsrqOffset;             /*Range:[0,160]*/  /* EUTRANС��RSRQ OFFSET */
    VOS_UINT16                              usLteServRsrpOffSet;                /*Range:[0,784]*/
    VOS_UINT16                              usLteServRsrqOffSet;                /*Range:[0,256]*/
    VOS_UINT16                              usUtranRscpOffSet;                  /*Range:[0,376]*/
    VOS_UINT16                              usUtranEcn0OffSet;                  /*Range:[0,248]*/
}WAS_W2L_CEll_RESEL_OFFSET_STRU;

/*****************************************************************************
 �ṹ��    : NVIM_UE_POSITION_CAPABILITIES_STRU
 �ṹ˵��  : UE�Ķ�λ�����ṹ                       ID:9093 en_NV_Item_UE_POSITION_CAPABILITIES
*****************************************************************************/
typedef struct
{
   VOS_UINT8                                ucGpsUeAssisted;                    /* UE������ GPS ��λ����: 0: ��֧��, 1: ֧�� */
   VOS_UINT8                                ucGpsUeBased;                       /* ����UE�� GPS ��λ����: 0: ��֧��, 1: ֧�� */
   VOS_UINT8                                ucGpsUeStandalone;                  /* UE������ GPS ��λ����: 0: ��֧��, 1: ֧�� */
   VOS_UINT8                                ucGpsValidInPch;                    /* PCH̬�µ� GPS ��λ����(��W ģʹ��): 0: ��֧��, 1: ֧�� */
   VOS_UINT8                                ucLcsVaCapability;                  /* LCS VALUE ADD��λ����(��G ģʹ��): 0: ��֧��, 1: ֧�� */
   VOS_UINT8                                ucAddPosCapability;                 /* ���ӵĶ�λ����(��G ģʹ��): 0: ��֧��, 1: ֧�� */

   VOS_UINT8                                aucRsv[2];                          /* ����λ */
}NVIM_UE_POSITION_CAPABILITIES_STRU;


/*****************************************************************************
 �ṹ��    : WAS_NVIM_PLMN_SEARCH_THRESHOLD_STRU
 �ṹ˵��  : ��NV�ж�ȡ�������ȫƵ������������      ID:8483 en_NV_Item_Plmn_Search_Threshold
*****************************************************************************/
typedef struct
{
    VOS_INT8                                cBgSearchHighQulityThreshold;       /* ������RSSI���������� */
    VOS_INT8                                cOtherSearchHighQulityThreshold;    /* ������RSSI���������� */
    VOS_INT8                                cLowQulityThreshold;                /* RSSI���������� */
    VOS_UINT8                               ucInterRatMeasOffset;               /* ����ͣ��ϵͳ���������ϼ�ȥ�ĳ��� */
}WAS_NVIM_PLMN_SEARCH_THRESHOLD_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_PLMN_SEARCH_FLOW_STRU
 �ṹ˵��  : ��NV�ж�ȡ�������ȫƵ������������     ID:8484  en_NV_Item_Plmn_Search_Flow
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucBgLowQulityFreqScrhFlag;          /* �����ѵ�����Ƶ���Ƿ���Ҫ�ѱ�־*/
    VOS_UINT8                               ucBgMultipleFreqScrhFlag;           /* �����ѱ�Ƶ���Ƿ���Ҫ�ѱ�־*/
    VOS_UINT8                               ucPlmnListLowQulityFreqScrhFlag;    /* PLMNLIST������Ƶ���Ƿ���Ҫ�ѱ�־*/
    VOS_UINT8                               ucPlmnListMultipleFreqScrhFlag;     /* PLMNLIST��Ƶ���Ƿ���Ҫ�ѱ�־*/
    VOS_UINT8                               ucOtherLowQulityFreqScrhFlag;       /* �����������̵�����Ƶ���Ƿ���Ҫ�ѱ�־*/
    VOS_UINT8                               ucOtherMultipleFreqScrhFlag;        /* �����������̱�Ƶ���Ƿ���Ҫ�ѱ�־*/
    VOS_UINT8                               aucReserve1[2];
}WAS_NVIM_PLMN_SEARCH_FLOW_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_ALL_BAND_SEARCH_PARA_STRU
 �ṹ˵��  : ��NV�ж�ȡ�������ȫƵ�����������ò��� ID:8485 en_NV_Item_All_Band_Search_Para
*****************************************************************************/
typedef struct
{
    VOS_UINT32                              ulRawScanFftFlag;                   /* ����band�Ĵ�ɨ�㷨 */
    VOS_UINT8                               aucReserv[2];                       /* 4�ֽڶ��룬�����ֽ� */
    VOS_UINT8                               ucFftFineScanFreqOffsetNum;         /* FFT�㷨ϸɨʱȡ����Ƶ���ƫ��Ƶ�����*/
    VOS_UINT8                               ucCellSearchFreqNum;                /* ϸɨ��һ��Ƶ����Ҫ��С��������Ƶ�����*/
    VOS_UINT8                               ucMultipleSrchFreqOffsetNum;        /* ��Ƶ������ʱ��ȡ����Ƶ���ƫ��Ƶ�����*/
    VOS_UINT8                               ucPlmnListHistoryFreqThreshold;     /* PLMNLIST����ʱ��ʷƵ��ĸ�������*/
    VOS_UINT8                               ucWcdmaRawScanFftStep;              /* FFT�㷨ʱ����������*/
    VOS_UINT8                               ucWcdmaRawScanRssiStep;             /* RSSI�㷨ʱ����������*/
}WAS_NVIM_ALL_BAND_SEARCH_PARA_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_WCDMA_IND_FREQ_STRU
 �ṹ˵��  : WCDMA IND FREQ��Ϣ�ṹ                 ID:8248 en_NV_Item_Wcdma_Ind_Freq UINT�ṹ���ɽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usUserIndFreq;
}WAS_NVIM_WCDMA_IND_FREQ_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_PDCP_LOSSLESS_SWITCH_STRU
 �ṹ˵��  : PDCP LOSSLESS SWITCH��Ϣ�ṹ           ID:8324 en_NV_Item_PDCP_LossLess_Switch UINT�ṹ���ɽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usNvPdcpLossLessSwitch;    /*Range:[0,1]*/    /* PDCP ����Ǩ�ƿ��� */
}WAS_NVIM_PDCP_LOSSLESS_SWITCH_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_OLPC_MAPWEIGHT_PARA_STRU
 �ṹ˵��  : WCDMA OLPC MAPWEIGHT PARA��Ϣ�ṹ      ID:8525 en_NV_Item_Wcdma_OLPC_MapWeight_Para UINT�ṹ���ɽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              ausMapWeight[WAS_MAPWEIGHT_MAX_NUM];    /*TOT OLPC�㷨����*/
}WAS_NVIM_OLPC_MAPWEIGHT_PARA_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_W_CELLSRCH_MEAS_PARA
 �ṹ˵��  : W_CELLSRCH_MEAS_PARA��Ϣ�ṹ           ID:8256 ����NV��
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usSysInfoRcvOptimSwitch;
    VOS_UINT16                              usPIOptimSwitch;
    VOS_UINT16                              usCellSrchMeasOptimSwitch;
    VOS_UINT16                              usCellSrchPeriod;
    VOS_INT16                               sCsStartRSCPThreshold;
    VOS_INT16                               sCsStopRSCPThreshold;
    VOS_INT16                               sCsStartECN0Threshold;
    VOS_INT16                               sCsStopECN0Threshold;
    VOS_UINT16                              usMeasIntraNCellNum;
    VOS_UINT16                              usMeasFilterFactor;
}WAS_NVIM_W_CELLSRCH_MEAS_PARA;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_UE_ACCESS_CAPA
 �ṹ˵��  : UE_ACCESS_CAPA��Ϣ�ṹ                 ID:8264 ����NV��
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               aucWasUeAccessCapa[WAS_UE_ACCESS_CAPA_NUM];
}WAS_NVIM_UE_ACCESS_CAPA;

/*****************************************************************************
 �ṹ��    : NV_ITEM_BG_IRAT_LIST_STRU
 �ṹ˵��  : BG_IRAT_LIST��Ϣ�ṹ                   ID:8487 ����NV��
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucValid;
    VOS_UINT8                               ucReserve;
    VOS_UINT16                              usBgIratListTime;                   /*Range:[6,65536]*/
}NV_ITEM_BG_IRAT_LIST_STRU;


/*****************************************************************************
 �ṹ��    : WAS_NVIM_T_CR_MAX_STRU
 Э�����  : 10.3.2.3 Cell selection and re-selection info for SIB3/4
 ASN.1���� : T_CRMax
 �ṹ˵��  : �����ƶ�������
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucTCrMax;       /* ��λ:10s��0��ʾ��ʹ�ã�(0, 3, 6, 12, 18, 24) */
    VOS_UINT8                           ucNCr;          /* ucTCRMax��Ϊ0ʱ��Ч��default 8��Integer(1..16) */
    VOS_UINT8                           ucTCrMaxHyst;   /* ucTCRMax��Ϊ0ʱ��Ч����λ:1s��0��ʾ��ʹ�ã�(0, 10, 20, 30, 40, 50, 60, 70) */
    VOS_UINT8                           ucReserve;
}WAS_NVIM_T_CR_MAX_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NV_OOS_RL_FAIL_PARA_STRU
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucOosTimerLen;
    PS_BOOL_ENUM_UINT8                      enT313UseDefaultValueFlg;
    VOS_UINT8                               ucReserve[2];
}WAS_NV_OOS_RL_FAIL_PARA_STRU;
/*****************************************************************************
 �ṹ��    : NVIM_SBM_CUSTOM_DUAL_IMSI_STRU
 �ṹ˵��  : �ձ���EMOIBLE�����е�plmn��Ϣ����plmn LTE��Ҫ�õ�
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           aucJapanEmMcc[3];  /* �ձ�EMBILE�����MCC��Ϣ */
    VOS_UINT8                           ucJapanEmMncCount; /* �ձ�EMBILE�����MNC���ȣ�2����3 */
    VOS_UINT8                           aucJapanEmMnc[3];  /* �ձ�EMBILE�����MNC��Ϣ,����Ϊ��λ����λ��f */
    VOS_UINT8                           ucReserve;
} NVIM_JAPAN_EM_PLMN_INFO_STRU;
/*****************************************************************************
 �ṹ��    : NVIM_SBM_CUSTOM_DUAL_IMSI_STRU
 �ṹ˵��  : ����˫imsi���غ�MCC��Ϣ
*****************************************************************************/

typedef struct
{
    VOS_UINT8                           ucSbmCustomDualImsiFlg;
    VOS_UINT8                           aucJapanMcc[3];      /* �ձ�������һ��MCC */
    VOS_UINT8                           aucJapanMcc1[3];     /* �ձ���������һ��MCC */
    VOS_UINT8                           ucJapanSbmMncCount;  /* �ձ����������MNC���� */
    VOS_UINT32                          aulJapanSbmMnc[5];   /* �ձ�������������5��MNC,����չ */
    NVIM_JAPAN_EM_PLMN_INFO_STRU        stJapanEmPlmnInfo;   /* �ձ���EMOBILE�����plmn��Ϣ */
    VOS_UINT8                           ucSbmOosTimerLen;    /* פ�����ձ������������������Ķ�ʱ������ʱǰֻ��band1��band11 */
    VOS_UINT8                           aucReserve[3];
} NVIM_SBM_CUSTOM_DUAL_IMSI_STRU;

/*****************************************************************************
 �ṹ��    : NVIM_SBM_CUSTOM_DUAL_IMSI_STRU_NEW
 �ṹ˵��  : ����˫imsi���غ�MCC��Ϣ
*****************************************************************************/

typedef struct
{
    VOS_UINT8                           ucSbmCustomDualImsiFlg;/* ˫Imsi�ܿ��� */
    VOS_UINT8                           ucDualImsiCellSearchChkFlg; /* �Ƿ���������ʱ��band���  */
    VOS_UINT8                           aucReserve[2];       /* ����λ */
    VOS_UINT8                           ucSbmOosTimerLen;    /* פ�����ձ������������������Ķ�ʱ�� */
    VOS_UINT8                           aucJapanMcc[3];      /* �ձ�������һ��MCC */
    VOS_UINT8                           aucJapanMcc1[3];     /* �ձ���������һ��MCC */
    VOS_UINT8                           ucJapanSbmMncCount;  /* �ձ����������MNC���� */
    VOS_UINT32                          aulJapanSbmMnc[5];   /* �ձ�������������5��MNC,����չ */
    NVIM_JAPAN_EM_PLMN_INFO_STRU        stJapanEmPlmnInfo;   /* �ձ���EMOBILE�����plmn��Ϣ */
    VOS_UINT32                          ulSbmSupBandInJapan;         /* �������ձ�����֧�ֵ�band�������ȫ1����Ϊ֧�ֵ�band�������ƣ�֧��UE֧�ֵ�����band */
    VOS_UINT32                          ulEmSupBandInJapan;          /* EM���ձ�����֧�ֵ�band�������ȫ1����Ϊ֧�ֵ�band�������ƣ�֧��UE֧�ֵ�����band */
    VOS_UINT32                          ulOtherOperateSupBandInJapan;/* ������Ӫ�����ձ�����֧�ֵ�band�������ȫ1����Ϊ֧�ֵ�band�������ƣ�֧��UE֧�ֵ�����band */
    VOS_UINT32                          ulSupBandOutJapan;           /* �ձ�����֧�ֵ�band,���ȫ1����Ϊ֧�ֵ�band�������ƣ�֧��UE֧�ֵ�����band */
    VOS_UINT32                          ulLteDelWcdmaBandInJapan;    /* �ձ�����פ��Lteʱ��Ҫ���ε�W��band,���ȫ1����Ϊ��Ҫ�������е�W��band */
} NVIM_SBM_CUSTOM_DUAL_IMSI_STRU_NEW;

/*****************************************************************************
 �ṹ��    : NVIM_SBM_CUSTOM_DUAL_IMSI_STRU
 �ṹ˵��  : WAS��˫imsi��Ϣ
*****************************************************************************/
typedef struct
{
    PS_BOOL_ENUM_UINT8                      enNvSbmDualImsiFlg;     /* ����˫imsi�����Ƿ�򿪣�Ĭ�Ϲرգ� */
    PS_BOOL_ENUM_UINT8                      enDualImsiCellSearchChkFlg; /* �Ƿ���������ʱ��band���  */
    VOS_UINT8                               ucSbmOosTimerLen;       /* פ�����ձ������������������Ķ�ʱ������ʱǰֻ��band1��band11 */
    VOS_UINT8                               ucJapanSbmMncCount;     /* �ձ����������MNC���� */
    VOS_UINT32                              aulJapanSbmMnc[5];      /* �ձ�������������5��MNC,����չ֧�ֲ��� */
    VOS_UINT32                              ulJapanMcc;             /* �ձ�������һ��MCC */
    VOS_UINT32                              ulJapanMcc1;            /* �ձ���������һ��MCC */
    VOS_UINT32                              ulEmMcc;                /* �ձ�����embile�����MCC */
    VOS_UINT32                              ulEmMnc;                /* �ձ�����embile�����MNC */
    VOS_UINT32                              ulSbmSupBandInJapan;    /* �������ձ�����֧�ֵ�band�������ȫ1����Ϊ֧�ֵ�band�������ƣ�֧��UE֧�ֵ�����band */
    VOS_UINT32                              ulEmSupBandInJapan;      /* EM���ձ�����֧�ֵ�band�������ȫ1����Ϊ֧�ֵ�band�������ƣ�֧��UE֧�ֵ�����band */
    VOS_UINT32                              ulOtherOperateSupBandInJapan;/* ������Ӫ�����ձ�����֧�ֵ�band�������ȫ1����Ϊ֧�ֵ�band�������ƣ�֧��UE֧�ֵ�����band */
    VOS_UINT32                              ulSupBandOutJapan;        /* �ձ�����֧�ֵ�band,���ȫ1����Ϊ֧�ֵ�band�������ƣ�֧��UE֧�ֵ�����band */
} WAS_NV_SBM_CUSTOM_DUAL_IMSI_STRU;
/*****************************************************************************
 �ṹ��    : WAS_NV_YOIGO_CUSTOM_PARA_INFO_STRU
 �ṹ˵��  : YOIGO���ƿ��غ�PLMN��Ϣ
*****************************************************************************/
typedef struct
{
    PS_BOOL_ENUM_UINT8            enYoigoCustomSwitchFlag;          /* YOIGO���ƿ����Ƿ�򿪱�־��Ĭ�Ϲر� */
    VOS_UINT8                     aucReserve[3];                    /* ����λ */
    VOS_UINT32                    ulYoigoMcc;                       /* YOIGO�����MCC */
    VOS_UINT32                    ulYoigoMnc;                       /* YOIGO�����MNC */
}WAS_NV_YOIGO_CUSTOM_PARA_INFO_STRU;

typedef struct
{
    VOS_UINT8                   aucUeWcdmaBandPriodiry[NVIM_MAX_FDD_FREQ_BANDS_NUM];
}NVIM_WAS_FREQ_BAND_PRIORITY_STRU;


typedef struct
{
    VOS_UINT16                              usCSHandoverTime;                   /* cs�л���Ҫ��Ĭ��ʱ�䣬������ʱ��������ϱ� */
    VOS_UINT8                               aucReserve[2];                     /* ����λ */
}WAS_ERR_LOG_CS_HO_LEN_STRU;

/*****************************************************************************
 �ṹ��    : WAS_PLMN_ID_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  :PLMN���ݽṹ
*****************************************************************************/

typedef struct
{
    VOS_UINT32                          ulMcc;              /* MCC,3 bytes      */
    VOS_UINT32                          ulMnc;              /* MNC,2 or 3 bytes */
}WAS_PLMN_ID_STRU;

/*****************************************************************************
 �ṹ��    : WAS_CSFB_MCC_BAND_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  :���Ҷ���ȫƵ��������band���ݽṹ
*****************************************************************************/
typedef struct
{
    WAS_PLMN_ID_STRU        stPlmn;
    VOS_UINT32              ulSupportWBand;
}WAS_CSFB_MCC_BAND_STRU;

/*****************************************************************************
 �ṹ��    : WAS_CSFB_MCC_BAND_INFO_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : CSFBʱ���ݹ��Ҷ���ȫƵ��������band
*****************************************************************************/
typedef struct
{
    VOS_UINT32                   ulMccNum;                                      /* ָʾ������MCC��Ч */
    WAS_CSFB_MCC_BAND_STRU       astUeCapMccBand[WAS_MAX_CSFB_MCC_BAND_NUM];
}WAS_CSFB_MCC_BAND_INFO_STRU;
/*****************************************************************************
 �ṹ��    : WAS_CSFB_SEARCH_CTRL_INFO_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : CSFBʱ���ݶ�ʱ�������С��
*****************************************************************************/
typedef struct
{
    VOS_UINT8                          ucCsfbSearchCtrlInfo;               /* CSFBʱW�������Ŀ���NV,��1bit��ʾ�Ƿ��������С��
                                                                              ��2bit��ʾ�Ƿ�����פ��ָ��С������ǿ��С�� */
    VOS_UINT8                          ucCsfbDetectCellNum;                /* �������С���ĸ��� */
    VOS_UINT8                          ucReserve1;                          
    VOS_UINT8                          ucReserve2;
}WAS_CSFB_SEARCH_CTRL_INFO_STRU;

/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/


/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/


/*****************************************************************************
  9 OTHERS
*****************************************************************************/

#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif





#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of WasNvInterface.h */