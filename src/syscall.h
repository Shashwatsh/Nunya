/*
Copyright (C) 2015 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#ifndef SYSCALL_H
#define SYSCALL_H

#include "kerneltypes.h"

#define SYSCALL_exit     1
#define SYSCALL_testcall 2
#define SYSCALL_yield    3
// TODO: change these syscall numbers
#define SYSCALL_clock_read 4
#define SYSCALL_sleep 5
#define SYSCALL_rtc_read 6

#define SYSCALL_window_create 200
#define SYSCALL_window_set_border_color 201
#define SYSCALL_window_draw_line 202
#define SYSCALL_window_draw_arc 203
#define SYSCALL_window_draw_circle 204
#define SYSCALL_window_draw_char 205
#define SYSCALL_window_draw_string 206

uint32_t syscall(uint32_t n, uint32_t a, uint32_t b, uint32_t c, uint32_t d,
                 uint32_t e);

static inline int32_t exit(uint32_t status) {
    return syscall(SYSCALL_exit, status, 0, 0, 0, 0);
}

static inline int32_t testcall(int x) {
    return syscall(SYSCALL_testcall, x, 0, 0, 0, 0);
}

static inline int32_t yield() {
    return syscall(SYSCALL_yield, 0, 0, 0, 0, 0);
}

// MARK Module System call includes

#include "sys_window.h"
#include "sys_clock.h"
#include "sys_rtc.h"

#endif