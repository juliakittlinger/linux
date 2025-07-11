/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Intel Core SoC Power Management Controller Header File
 *
 * Copyright (c) 2016, Intel Corporation.
 * All Rights Reserved.
 *
 * Authors: Rajneesh Bhardwaj <rajneesh.bhardwaj@intel.com>
 *          Vishwanath Somayaji <vishwanath.somayaji@intel.com>
 */

#ifndef PMC_CORE_H
#define PMC_CORE_H

#include <linux/acpi.h>
#include <linux/bits.h>
#include <linux/platform_device.h>

struct telem_endpoint;

#define SLP_S0_RES_COUNTER_MASK			GENMASK(31, 0)

#define PMC_BASE_ADDR_DEFAULT			0xFE000000
#define MAX_NUM_PMC			3
#define S0IX_BLK_SIZE			4

/* PCH query */
#define LPM_HEADER_OFFSET	1
#define LPM_REG_COUNT		28
#define LPM_MODE_OFFSET		1

/* Sunrise Point Power Management Controller PCI Device ID */
#define SPT_PMC_PCI_DEVICE_ID			0x9d21
#define SPT_PMC_BASE_ADDR_OFFSET		0x48
#define SPT_PMC_SLP_S0_RES_COUNTER_OFFSET	0x13c
#define SPT_PMC_PM_CFG_OFFSET			0x18
#define SPT_PMC_PM_STS_OFFSET			0x1c
#define SPT_PMC_MTPMC_OFFSET			0x20
#define SPT_PMC_MFPMC_OFFSET			0x38
#define SPT_PMC_LTR_IGNORE_OFFSET		0x30C
#define SPT_PMC_VRIC1_OFFSET			0x31c
#define SPT_PMC_MPHY_CORE_STS_0			0x1143
#define SPT_PMC_MPHY_CORE_STS_1			0x1142
#define SPT_PMC_MPHY_COM_STS_0			0x1155
#define SPT_PMC_MMIO_REG_LEN			0x1000
#define SPT_PMC_SLP_S0_RES_COUNTER_STEP		0x68
#define PMC_BASE_ADDR_MASK			~(SPT_PMC_MMIO_REG_LEN - 1)
#define MTPMC_MASK				0xffff0000
#define PPFEAR_MAX_NUM_ENTRIES			12
#define SPT_PPFEAR_NUM_ENTRIES			5
#define SPT_PMC_READ_DISABLE_BIT		0x16
#define SPT_PMC_MSG_FULL_STS_BIT		0x18
#define NUM_RETRIES				100
#define SPT_NUM_IP_IGN_ALLOWED			17

#define SPT_PMC_LTR_CUR_PLT			0x350
#define SPT_PMC_LTR_CUR_ASLT			0x354
#define SPT_PMC_LTR_SPA				0x360
#define SPT_PMC_LTR_SPB				0x364
#define SPT_PMC_LTR_SATA			0x368
#define SPT_PMC_LTR_GBE				0x36C
#define SPT_PMC_LTR_XHCI			0x370
#define SPT_PMC_LTR_RESERVED			0x374
#define SPT_PMC_LTR_ME				0x378
#define SPT_PMC_LTR_EVA				0x37C
#define SPT_PMC_LTR_SPC				0x380
#define SPT_PMC_LTR_AZ				0x384
#define SPT_PMC_LTR_LPSS			0x38C
#define SPT_PMC_LTR_CAM				0x390
#define SPT_PMC_LTR_SPD				0x394
#define SPT_PMC_LTR_SPE				0x398
#define SPT_PMC_LTR_ESPI			0x39C
#define SPT_PMC_LTR_SCC				0x3A0
#define SPT_PMC_LTR_ISH				0x3A4

/* Sunrise Point: PGD PFET Enable Ack Status Registers */
enum ppfear_regs {
	SPT_PMC_XRAM_PPFEAR0A = 0x590,
	SPT_PMC_XRAM_PPFEAR0B,
	SPT_PMC_XRAM_PPFEAR0C,
	SPT_PMC_XRAM_PPFEAR0D,
	SPT_PMC_XRAM_PPFEAR1A,
};

#define SPT_PMC_BIT_PMC				BIT(0)
#define SPT_PMC_BIT_OPI				BIT(1)
#define SPT_PMC_BIT_SPI				BIT(2)
#define SPT_PMC_BIT_XHCI			BIT(3)
#define SPT_PMC_BIT_SPA				BIT(4)
#define SPT_PMC_BIT_SPB				BIT(5)
#define SPT_PMC_BIT_SPC				BIT(6)
#define SPT_PMC_BIT_GBE				BIT(7)

#define SPT_PMC_BIT_SATA			BIT(0)
#define SPT_PMC_BIT_HDA_PGD0			BIT(1)
#define SPT_PMC_BIT_HDA_PGD1			BIT(2)
#define SPT_PMC_BIT_HDA_PGD2			BIT(3)
#define SPT_PMC_BIT_HDA_PGD3			BIT(4)
#define SPT_PMC_BIT_RSVD_0B			BIT(5)
#define SPT_PMC_BIT_LPSS			BIT(6)
#define SPT_PMC_BIT_LPC				BIT(7)

#define SPT_PMC_BIT_SMB				BIT(0)
#define SPT_PMC_BIT_ISH				BIT(1)
#define SPT_PMC_BIT_P2SB			BIT(2)
#define SPT_PMC_BIT_DFX				BIT(3)
#define SPT_PMC_BIT_SCC				BIT(4)
#define SPT_PMC_BIT_RSVD_0C			BIT(5)
#define SPT_PMC_BIT_FUSE			BIT(6)
#define SPT_PMC_BIT_CAMREA			BIT(7)

#define SPT_PMC_BIT_RSVD_0D			BIT(0)
#define SPT_PMC_BIT_USB3_OTG			BIT(1)
#define SPT_PMC_BIT_EXI				BIT(2)
#define SPT_PMC_BIT_CSE				BIT(3)
#define SPT_PMC_BIT_CSME_KVM			BIT(4)
#define SPT_PMC_BIT_CSME_PMT			BIT(5)
#define SPT_PMC_BIT_CSME_CLINK			BIT(6)
#define SPT_PMC_BIT_CSME_PTIO			BIT(7)

#define SPT_PMC_BIT_CSME_USBR			BIT(0)
#define SPT_PMC_BIT_CSME_SUSRAM			BIT(1)
#define SPT_PMC_BIT_CSME_SMT			BIT(2)
#define SPT_PMC_BIT_RSVD_1A			BIT(3)
#define SPT_PMC_BIT_CSME_SMS2			BIT(4)
#define SPT_PMC_BIT_CSME_SMS1			BIT(5)
#define SPT_PMC_BIT_CSME_RTC			BIT(6)
#define SPT_PMC_BIT_CSME_PSF			BIT(7)

#define SPT_PMC_BIT_MPHY_LANE0			BIT(0)
#define SPT_PMC_BIT_MPHY_LANE1			BIT(1)
#define SPT_PMC_BIT_MPHY_LANE2			BIT(2)
#define SPT_PMC_BIT_MPHY_LANE3			BIT(3)
#define SPT_PMC_BIT_MPHY_LANE4			BIT(4)
#define SPT_PMC_BIT_MPHY_LANE5			BIT(5)
#define SPT_PMC_BIT_MPHY_LANE6			BIT(6)
#define SPT_PMC_BIT_MPHY_LANE7			BIT(7)

#define SPT_PMC_BIT_MPHY_LANE8			BIT(0)
#define SPT_PMC_BIT_MPHY_LANE9			BIT(1)
#define SPT_PMC_BIT_MPHY_LANE10			BIT(2)
#define SPT_PMC_BIT_MPHY_LANE11			BIT(3)
#define SPT_PMC_BIT_MPHY_LANE12			BIT(4)
#define SPT_PMC_BIT_MPHY_LANE13			BIT(5)
#define SPT_PMC_BIT_MPHY_LANE14			BIT(6)
#define SPT_PMC_BIT_MPHY_LANE15			BIT(7)

#define SPT_PMC_BIT_MPHY_CMN_LANE0		BIT(0)
#define SPT_PMC_BIT_MPHY_CMN_LANE1		BIT(1)
#define SPT_PMC_BIT_MPHY_CMN_LANE2		BIT(2)
#define SPT_PMC_BIT_MPHY_CMN_LANE3		BIT(3)

#define SPT_PMC_VRIC1_SLPS0LVEN			BIT(13)
#define SPT_PMC_VRIC1_XTALSDQDIS		BIT(22)

/* Cannonlake Power Management Controller register offsets */
#define CNP_PMC_SLPS0_DBG_OFFSET		0x10B4
#define CNP_PMC_PM_CFG_OFFSET			0x1818
#define CNP_PMC_SLP_S0_RES_COUNTER_OFFSET	0x193C
#define CNP_PMC_LTR_IGNORE_OFFSET		0x1B0C
/* Cannonlake: PGD PFET Enable Ack Status Register(s) start */
#define CNP_PMC_HOST_PPFEAR0A			0x1D90

#define CNP_PMC_LATCH_SLPS0_EVENTS		BIT(31)

#define CNP_PMC_MMIO_REG_LEN			0x2000
#define CNP_PPFEAR_NUM_ENTRIES			8
#define CNP_PMC_READ_DISABLE_BIT		22
#define CNP_NUM_IP_IGN_ALLOWED			19
#define CNP_PMC_LTR_CUR_PLT			0x1B50
#define CNP_PMC_LTR_CUR_ASLT			0x1B54
#define CNP_PMC_LTR_SPA				0x1B60
#define CNP_PMC_LTR_SPB				0x1B64
#define CNP_PMC_LTR_SATA			0x1B68
#define CNP_PMC_LTR_GBE				0x1B6C
#define CNP_PMC_LTR_XHCI			0x1B70
#define CNP_PMC_LTR_RESERVED			0x1B74
#define CNP_PMC_LTR_ME				0x1B78
#define CNP_PMC_LTR_EVA				0x1B7C
#define CNP_PMC_LTR_SPC				0x1B80
#define CNP_PMC_LTR_AZ				0x1B84
#define CNP_PMC_LTR_LPSS			0x1B8C
#define CNP_PMC_LTR_CAM				0x1B90
#define CNP_PMC_LTR_SPD				0x1B94
#define CNP_PMC_LTR_SPE				0x1B98
#define CNP_PMC_LTR_ESPI			0x1B9C
#define CNP_PMC_LTR_SCC				0x1BA0
#define CNP_PMC_LTR_ISH				0x1BA4
#define CNP_PMC_LTR_CNV				0x1BF0
#define CNP_PMC_LTR_EMMC			0x1BF4
#define CNP_PMC_LTR_UFSX2			0x1BF8

#define LTR_DECODED_VAL				GENMASK(9, 0)
#define LTR_DECODED_SCALE			GENMASK(12, 10)
#define LTR_REQ_SNOOP				BIT(15)
#define LTR_REQ_NONSNOOP			BIT(31)

#define ICL_PPFEAR_NUM_ENTRIES			9
#define ICL_NUM_IP_IGN_ALLOWED			20
#define ICL_PMC_LTR_WIGIG			0x1BFC
#define ICL_PMC_SLP_S0_RES_COUNTER_STEP		0x64

#define LPM_MAX_NUM_MODES			8
#define LPM_DEFAULT_PRI				{ 7, 6, 2, 5, 4, 1, 3, 0 }

#define GET_X2_COUNTER(v)			((v) >> 1)
#define LPM_STS_LATCH_MODE			BIT(31)

#define TGL_PMC_SLP_S0_RES_COUNTER_STEP		0x7A
#define TGL_PMC_LTR_THC0			0x1C04
#define TGL_PMC_LTR_THC1			0x1C08
#define TGL_NUM_IP_IGN_ALLOWED			23
#define TGL_PMC_LPM_RES_COUNTER_STEP_X2		61	/* 30.5us * 2 */

#define ADL_PMC_LTR_SPF				0x1C00
#define ADL_NUM_IP_IGN_ALLOWED			23
#define ADL_PMC_SLP_S0_RES_COUNTER_OFFSET	0x1098

/*
 * Tigerlake Power Management Controller register offsets
 */
#define TGL_LPM_STS_LATCH_EN_OFFSET		0x1C34
#define TGL_LPM_EN_OFFSET			0x1C78
#define TGL_LPM_RESIDENCY_OFFSET		0x1C80

/* Tigerlake Low Power Mode debug registers */
#define TGL_LPM_STATUS_OFFSET			0x1C3C
#define TGL_LPM_LIVE_STATUS_OFFSET		0x1C5C
#define TGL_LPM_PRI_OFFSET			0x1C7C
#define TGL_LPM_NUM_MAPS			6

/* Tigerlake PSON residency register */
#define TGL_PSON_RESIDENCY_OFFSET		0x18f8
#define TGL_PSON_RES_COUNTER_STEP		0x7A

/* Extended Test Mode Register 3 (CNL and later) */
#define ETR3_OFFSET				0x1048
#define ETR3_CF9GR				BIT(20)
#define ETR3_CF9LOCK				BIT(31)

/* Extended Test Mode Register LPM bits (TGL and later */
#define ETR3_CLEAR_LPM_EVENTS			BIT(28)

/* Alder Lake Power Management Controller register offsets */
#define ADL_LPM_EN_OFFSET			0x179C
#define ADL_LPM_RESIDENCY_OFFSET		0x17A4
#define ADL_LPM_NUM_MODES			2
#define ADL_LPM_NUM_MAPS			14

/* Alder Lake Low Power Mode debug registers */
#define ADL_LPM_STATUS_OFFSET			0x170C
#define ADL_LPM_PRI_OFFSET			0x17A0
#define ADL_LPM_STATUS_LATCH_EN_OFFSET		0x1704
#define ADL_LPM_LIVE_STATUS_OFFSET		0x1764

/* Meteor Lake Power Management Controller register offsets */
#define MTL_LPM_EN_OFFSET			0x1798
#define MTL_LPM_RESIDENCY_OFFSET		0x17A0

/* Meteor Lake Low Power Mode debug registers */
#define MTL_LPM_PRI_OFFSET			0x179C
#define MTL_LPM_STATUS_LATCH_EN_OFFSET		0x16F8
#define MTL_LPM_STATUS_OFFSET			0x1700
#define MTL_LPM_LIVE_STATUS_OFFSET		0x175C
#define MTL_PMC_LTR_IOE_PMC			0x1C0C
#define MTL_PMC_LTR_ESE				0x1BAC
#define MTL_PMC_LTR_RESERVED			0x1BA4
#define MTL_IOE_PMC_MMIO_REG_LEN		0x23A4
#define MTL_SOCM_NUM_IP_IGN_ALLOWED		25
#define MTL_SOC_PMC_MMIO_REG_LEN		0x2708
#define MTL_PMC_LTR_SPG				0x1B74
#define ARL_SOCS_PMC_LTR_RESERVED		0x1B88
#define ARL_SOCS_NUM_IP_IGN_ALLOWED		26
#define ARL_PMC_LTR_DMI3			0x1BE4
#define ARL_PCH_PMC_MMIO_REG_LEN		0x2720

/* Meteor Lake PGD PFET Enable Ack Status */
#define MTL_SOCM_PPFEAR_NUM_ENTRIES		8
#define MTL_IOE_PPFEAR_NUM_ENTRIES		10
#define ARL_SOCS_PPFEAR_NUM_ENTRIES		9

/* Die C6 from PUNIT telemetry */
#define MTL_PMT_DMU_DIE_C6_OFFSET		15
#define MTL_PMT_DMU_GUID			0x1A067102
#define ARL_PMT_DMU_GUID			0x1A06A000

#define LNL_PMC_MMIO_REG_LEN			0x2708
#define LNL_PMC_LTR_OSSE			0x1B88
#define LNL_NUM_IP_IGN_ALLOWED			27
#define LNL_PPFEAR_NUM_ENTRIES			12
#define LNL_S0IX_BLOCKER_OFFSET			0x2004

/* Panther Lake Power Management Controller register offsets */
#define PTL_LPM_NUM_MAPS			14
#define PTL_PMC_LTR_SATA2			0x1B90
#define PTL_PMC_LTR_PMC				0x1BA8
#define PTL_PMC_LTR_CUR_ASLT			0x1C28
#define PTL_PMC_LTR_CUR_PLT			0x1C2C
#define PTL_PCD_PMC_MMIO_REG_LEN		0x31A8

/* SSRAM PMC Device ID */
/* LNL */
#define PMC_DEVID_LNL_SOCM	0xa87f

/* PTL */
#define PMC_DEVID_PTL_PCDH	0xe37f
#define PMC_DEVID_PTL_PCDP	0xe47f

/* ARL */
#define PMC_DEVID_ARL_SOCM	0x777f
#define PMC_DEVID_ARL_SOCS	0xae7f
#define PMC_DEVID_ARL_IOEP	0x7ecf
#define PMC_DEVID_ARL_PCHS	0x7f27

/* MTL */
#define PMC_DEVID_MTL_SOCM	0x7e7f
#define PMC_DEVID_MTL_IOEP	0x7ecf
#define PMC_DEVID_MTL_IOEM	0x7ebf

extern const char *pmc_lpm_modes[];

struct pmc_bit_map {
	const char *name;
	u32 bit_mask;
	u8 blk;
};

/**
 * struct pmc_reg_map - Structure used to define parameter unique to a
			PCH family
 * @pfear_sts:		Maps name of IP block to PPFEAR* bit
 * @mphy_sts:		Maps name of MPHY lane to MPHY status lane status bit
 * @pll_sts:		Maps name of PLL to corresponding bit status
 * @slps0_dbg_maps:	Array of SLP_S0_DBG* registers containing debug info
 * @ltr_show_sts:	Maps PCH IP Names to their MMIO register offsets
 * @s0ix_blocker_maps:	Maps name of IP block to S0ix blocker counter
 * @slp_s0_offset:	PWRMBASE offset to read SLP_S0 residency
 * @ltr_ignore_offset:	PWRMBASE offset to read/write LTR ignore bit
 * @regmap_length:	Length of memory to map from PWRMBASE address to access
 * @ppfear0_offset:	PWRMBASE offset to read PPFEAR*
 * @ppfear_buckets:	Number of 8 bits blocks to read all IP blocks from
 *			PPFEAR
 * @pm_cfg_offset:	PWRMBASE offset to PM_CFG register
 * @pm_read_disable_bit: Bit index to read PMC_READ_DISABLE
 * @slps0_dbg_offset:	PWRMBASE offset to SLP_S0_DEBUG_REG*
 * @s0ix_blocker_offset PWRMBASE offset to S0ix blocker counter
 *
 * Each PCH has unique set of register offsets and bit indexes. This structure
 * captures them to have a common implementation.
 */
struct pmc_reg_map {
	const struct pmc_bit_map **pfear_sts;
	const struct pmc_bit_map *mphy_sts;
	const struct pmc_bit_map *pll_sts;
	const struct pmc_bit_map **slps0_dbg_maps;
	const struct pmc_bit_map *ltr_show_sts;
	const struct pmc_bit_map *msr_sts;
	const struct pmc_bit_map **lpm_sts;
	const struct pmc_bit_map **s0ix_blocker_maps;
	const u32 slp_s0_offset;
	const int slp_s0_res_counter_step;
	const u32 ltr_ignore_offset;
	const int regmap_length;
	const u32 ppfear0_offset;
	const int ppfear_buckets;
	const u32 pm_cfg_offset;
	const int pm_read_disable_bit;
	const u32 slps0_dbg_offset;
	const u32 ltr_ignore_max;
	const u32 pm_vric1_offset;
	const u32 s0ix_blocker_offset;
	/* Low Power Mode registers */
	const int lpm_num_maps;
	const int lpm_num_modes;
	const int lpm_res_counter_step_x2;
	const u32 lpm_sts_latch_en_offset;
	const u32 lpm_en_offset;
	const u32 lpm_priority_offset;
	const u32 lpm_residency_offset;
	const u32 lpm_status_offset;
	const u32 lpm_live_status_offset;
	const u32 etr3_offset;
	const u8  *lpm_reg_index;
	const u32 pson_residency_offset;
	const u32 pson_residency_counter_step;
};

/**
 * struct pmc_info - Structure to keep pmc info
 * @devid:		device id of the pmc device
 * @map:		pointer to a pmc_reg_map struct that contains platform
 *			specific attributes
 */
struct pmc_info {
	u32 guid;
	u16 devid;
	const struct pmc_reg_map *map;
};

/**
 * struct pmc - pmc private info structure
 * @base_addr:		contains pmc base address
 * @regbase:		pointer to io-remapped memory location
 * @map:		pointer to pmc_reg_map struct that contains platform
 *			specific attributes
 * @lpm_req_regs:	List of substate requirements
 * @ltr_ign:		Holds LTR ignore data while suspended
 *
 * pmc contains info about one power management controller device.
 */
struct pmc {
	u64 base_addr;
	void __iomem *regbase;
	const struct pmc_reg_map *map;
	u32 *lpm_req_regs;
	u32 ltr_ign;
};

/**
 * struct pmc_dev - pmc device structure
 * @devs:		pointer to an array of pmc pointers
 * @pdev:		pointer to platform_device struct
 * @crystal_freq:	crystal frequency from cpuid
 * @dbgfs_dir:		path to debugfs interface
 * @pmc_xram_read_bit:	flag to indicate whether PMC XRAM shadow registers
 *			used to read MPHY PG and PLL status are available
 * @mutex_lock:		mutex to complete one transcation
 * @pkgc_res_cnt:	Array of PKGC residency counters
 * @num_of_pkgc:	Number of PKGC
 * @s0ix_counter:	S0ix residency (step adjusted)
 * @num_lpm_modes:	Count of enabled modes
 * @lpm_en_modes:	Array of enabled modes from lowest to highest priority
 * @suspend:		Function to perform platform specific suspend
 * @resume:		Function to perform platform specific resume
 *
 * pmc_dev contains info about power management controller device.
 */
struct pmc_dev {
	struct pmc *pmcs[MAX_NUM_PMC];
	struct dentry *dbgfs_dir;
	struct platform_device *pdev;
	unsigned int crystal_freq;
	int pmc_xram_read_bit;
	struct mutex lock; /* generic mutex lock for PMC Core */

	u64 s0ix_counter;
	int num_lpm_modes;
	int lpm_en_modes[LPM_MAX_NUM_MODES];
	void (*suspend)(struct pmc_dev *pmcdev);
	int (*resume)(struct pmc_dev *pmcdev);

	u64 *pkgc_res_cnt;
	u8 num_of_pkgc;

	bool has_die_c6;
	u32 die_c6_offset;
	struct telem_endpoint *punit_ep;
	struct pmc_info *regmap_list;
};

enum pmc_index {
	PMC_IDX_MAIN,
	PMC_IDX_IOE,
	PMC_IDX_PCH,
	PMC_IDX_MAX
};

/**
 * struct pmc_dev_info - Structure to keep PMC device info
 * @pci_func:		Function number of the primary PMC
 * @dmu_guid:		Die Management Unit GUID
 * @regmap_list:	Pointer to a list of pmc_info structure that could be
 *			available for the platform. When set, this field implies
 *			SSRAM support.
 * @map:		Pointer to a pmc_reg_map struct that contains platform
 *			specific attributes of the primary PMC
 * @suspend:		Function to perform platform specific suspend
 * @resume:		Function to perform platform specific resume
 * @init:		Function to perform platform specific init action
 */
struct pmc_dev_info {
	u8 pci_func;
	u32 dmu_guid;
	struct pmc_info *regmap_list;
	const struct pmc_reg_map *map;
	void (*suspend)(struct pmc_dev *pmcdev);
	int (*resume)(struct pmc_dev *pmcdev);
	int (*init)(struct pmc_dev *pmcdev, struct pmc_dev_info *pmc_dev_info);
};

extern const struct pmc_bit_map msr_map[];
extern const struct pmc_bit_map cnp_pfear_map[];
extern const struct pmc_bit_map *cnp_slps0_dbg_maps[];
extern const struct pmc_bit_map cnp_ltr_show_map[];
extern const struct pmc_reg_map cnp_reg_map;
extern const struct pmc_bit_map tgl_signal_status_map[];
extern const struct pmc_reg_map adl_reg_map;
extern const struct pmc_bit_map mtl_socm_pfear_map[];
extern const struct pmc_bit_map mtl_socm_d3_status_0_map[];
extern const struct pmc_bit_map mtl_socm_d3_status_1_map[];
extern const struct pmc_bit_map mtl_socm_vnn_req_status_0_map[];
extern const struct pmc_bit_map mtl_socm_vnn_req_status_1_map[];
extern const struct pmc_bit_map mtl_socm_vnn_req_status_2_map[];
extern const struct pmc_bit_map mtl_socm_vnn_misc_status_map[];
extern const struct pmc_bit_map mtl_socm_signal_status_map[];
extern const struct pmc_reg_map mtl_socm_reg_map;
extern const struct pmc_reg_map mtl_ioep_reg_map;

void pmc_core_get_tgl_lpm_reqs(struct platform_device *pdev);
int pmc_core_send_ltr_ignore(struct pmc_dev *pmcdev, u32 value, int ignore);

int pmc_core_resume_common(struct pmc_dev *pmcdev);
int get_primary_reg_base(struct pmc *pmc);
void pmc_core_get_low_power_modes(struct pmc_dev *pmcdev);
void pmc_core_punit_pmt_init(struct pmc_dev *pmcdev, u32 guid);
void pmc_core_set_device_d3(unsigned int device);

int generic_core_init(struct pmc_dev *pmcdev, struct pmc_dev_info *pmc_dev_info);

extern struct pmc_dev_info spt_pmc_dev;
extern struct pmc_dev_info cnp_pmc_dev;
extern struct pmc_dev_info icl_pmc_dev;
extern struct pmc_dev_info tgl_l_pmc_dev;
extern struct pmc_dev_info tgl_pmc_dev;
extern struct pmc_dev_info adl_pmc_dev;
extern struct pmc_dev_info mtl_pmc_dev;
extern struct pmc_dev_info arl_pmc_dev;
extern struct pmc_dev_info arl_h_pmc_dev;
extern struct pmc_dev_info lnl_pmc_dev;
extern struct pmc_dev_info ptl_pmc_dev;

void cnl_suspend(struct pmc_dev *pmcdev);
int cnl_resume(struct pmc_dev *pmcdev);

#define pmc_for_each_mode(mode, pmcdev)						\
	for (unsigned int __i = 0, __cond;					\
	     __cond = __i < (pmcdev)->num_lpm_modes,				\
	     __cond && ((mode) = (pmcdev)->lpm_en_modes[__i]),			\
	     __cond;								\
	     __i++)

#define DEFINE_PMC_CORE_ATTR_WRITE(__name)				\
static int __name ## _open(struct inode *inode, struct file *file)	\
{									\
	return single_open(file, __name ## _show, inode->i_private);	\
}									\
									\
static const struct file_operations __name ## _fops = {			\
	.owner		= THIS_MODULE,					\
	.open		= __name ## _open,				\
	.read		= seq_read,					\
	.write		= __name ## _write,				\
	.release	= single_release,				\
}

#endif /* PMC_CORE_H */
