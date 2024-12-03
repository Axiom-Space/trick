/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include <math.h>
#include "../include/waterclock.h"

/* default data job */
int waterclock_default_data( WATERCLOCK* WC ) {

    WC->time                            = 0.0 ;

    WC->input_flow                      = 1000;
    WC->intake_clock_spout_flowrate     = 0.0;
    WC->intake_overflow_flowrate        = 0.0;

    WC->intake_bucket_depth             = 100.0;
    WC->intake_bucket_diam              = 500.0;

    WC->intake_overflow_height          = 080.0 * WC->intake_bucket_depth;
    WC->intake_overflow_diameter        = 100.0;

    WC->intake_clock_spout_height       = 010.0;
    WC->intake_clock_spout_diameter     = 005.0;

    WC->timer_bucket_depth              = 120.0;
    WC->timer_bucket_diam               = 050.0;

    WC->intake_bucket_vol               = 0.0;
    WC->timer_bucket_vol                = 0.0;

    WC->total_ticks                     = 5;
    WC->current_tick                    = 0;

    WC->gravity                         = 9.81;

    return 0 ;
}

/* initialization job */
int waterclock_init( WATERCLOCK* WC) {

    if (WC->intake_overflow_height > WC->intake_bucket_depth) {
                  WC->intake_overflow_height = WC->intake_bucket_depth;
    }
    if (WC->intake_clock_spout_height > WC->intake_bucket_depth) {
                  WC->intake_clock_spout_height = WC->intake_bucket_depth;
    }
    if (WC->intake_overflow_height < 0) {
                  WC->intake_overflow_height = 0;
    }
    if (WC->intake_clock_spout_height < 0) {
                  WC->intake_clock_spout_height = 0;
    }
    WC->tick_gap = WC->timer_bucket_depth / WC->total_ticks ;

    return 0 ;
}
