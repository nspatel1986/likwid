/*
 * =======================================================================================
 *
 *      Filename:  perfmon_zen_counters.h
 *
 *      Description:  Counter Header File of perfmon module for AMD Family 17
 *
 *      Version:   <VERSION>
 *      Released:  <DATE>
 *
 *      Author:   Thomas Roehl (tr), thomas.roehl@googlemail.com
 *      Project:  likwid
 *
 *      Copyright (C) 2017 RRZE, University Erlangen-Nuremberg
 *
 *      This program is free software: you can redistribute it and/or modify it under
 *      the terms of the GNU General Public License as published by the Free Software
 *      Foundation, either version 3 of the License, or (at your option) any later
 *      version.
 *
 *      This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *      WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *      PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along with
 *      this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =======================================================================================
 */

#define NUM_COUNTERS_ZEN 12
#define NUM_COUNTERS_CORE_ZEN 8

#define ZEN_VALID_OPTIONS_PMC EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD
#define ZEN_VALID_OPTIONS_CBOX EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD|EVENT_OPTION_TID_MASK|EVENT_OPTION_NID_MASK

static RegisterMap zen_counter_map[NUM_COUNTERS_ZEN] = {
    /* Core counters */
    {"PMC0",PMC0, PMC, MSR_AMD16_PERFEVTSEL0, MSR_AMD16_PMC0, 0, 0, ZEN_VALID_OPTIONS_PMC},
    {"PMC1",PMC1, PMC, MSR_AMD16_PERFEVTSEL1, MSR_AMD16_PMC1, 0, 0, ZEN_VALID_OPTIONS_PMC},
    {"PMC2",PMC2, PMC, MSR_AMD16_PERFEVTSEL2, MSR_AMD16_PMC2, 0, 0, ZEN_VALID_OPTIONS_PMC},
    {"PMC3",PMC3, PMC, MSR_AMD16_PERFEVTSEL3, MSR_AMD16_PMC3, 0, 0, ZEN_VALID_OPTIONS_PMC},
    /* L2 cache counters */
    {"CPMC0",PMC4, CBOX0, MSR_AMD16_L2_PERFEVTSEL0, MSR_AMD16_L2_PMC0, 0, 0, ZEN_VALID_OPTIONS_CBOX},
    {"CPMC1",PMC5, CBOX0, MSR_AMD16_L2_PERFEVTSEL1, MSR_AMD16_L2_PMC1, 0, 0, ZEN_VALID_OPTIONS_CBOX},
    {"CPMC2",PMC6, CBOX0, MSR_AMD16_L2_PERFEVTSEL2, MSR_AMD16_L2_PMC2, 0, 0, ZEN_VALID_OPTIONS_CBOX},
    {"CPMC3",PMC7, CBOX0, MSR_AMD16_L2_PERFEVTSEL3, MSR_AMD16_L2_PMC3, 0, 0, ZEN_VALID_OPTIONS_CBOX},
    /* Northbridge counters */
    {"UPMC0",PMC8, UNCORE, MSR_AMD16_NB_PERFEVTSEL0, MSR_AMD16_NB_PMC0, 0, 0},
    {"UPMC1",PMC9, UNCORE, MSR_AMD16_NB_PERFEVTSEL1, MSR_AMD16_NB_PMC1, 0, 0},
    {"UPMC2",PMC10, UNCORE, MSR_AMD16_NB_PERFEVTSEL2, MSR_AMD16_NB_PMC2, 0, 0},
    {"UPMC3",PMC11, UNCORE, MSR_AMD16_NB_PERFEVTSEL3, MSR_AMD16_NB_PMC3, 0, 0}
};

static BoxMap zen_box_map[NUM_UNITS] = {
    [PMC] = {0, 0, 0, 0, 0, 0, 48},
    [UNCORE] = {0, 0, 0, 0, 0, 0, 48},
    [CBOX0] = {0, 0, 0, 0, 0, 0, 48},
};
