#ifndef __RL6231_H__
#define __RL6231_H__

#include <wdm.h>

#define RL6231_PLL_INP_MAX	50000000
#define RL6231_PLL_INP_MIN	256000
#define RL6231_PLL_N_MAX	0x1ff
#define RL6231_PLL_K_MAX	0x1f
#define RL6231_PLL_M_MAX	0xf

struct rl6231_pll_code {
	BOOLEAN m_bp; /* Indicates bypass m code or not. */
	BOOLEAN k_bp; /* Indicates bypass k code or not. */
	INT m_code;
	INT n_code;
	INT k_code;
};

NTSTATUS rl6231_calc_dmic_clk(int rate, int* clk);
NTSTATUS rl6231_pll_calc(const unsigned int freq_in,
	const unsigned int freq_out, struct rl6231_pll_code* pll_code);
NTSTATUS rl6231_get_clk_info(int sclk, int rate);
NTSTATUS rl6231_get_pre_div(unsigned int regval, int sft);

#endif /* __RL6231_H__ */