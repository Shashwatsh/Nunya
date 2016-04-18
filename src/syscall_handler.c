/*
Copyright (C) 2015 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#include "syscall.h"
#include "syscall_handler_fs.h"
#include "process.h"
#include "syscall_handler_window.h"
#include "syscall_handler_clock.h"
#include "syscall_handler_rtc.h"

uint32_t sys_exit(uint32_t code) {
    process_exit(code);
    return 0;
}

uint32_t sys_yield() {
    process_yield();
    return 0;
}

int32_t syscall_handler(uint32_t n, uint32_t a, uint32_t b, uint32_t c,
                        uint32_t d, uint32_t e) {
    switch (n) {
        case SYSCALL_yield:
            return sys_yield();
        case SYSCALL_exit:
            return sys_exit(a);
        case SYSCALL_clock_read:
            return sys_clock_read((clock_t *)a);
        case SYSCALL_sleep:
            return sys_sleep(a);
        case SYSCALL_rtc_read:
            return sys_rtc_read((struct rtc_time *)a);
        case SYSCALL_open:
            return sys_fs_open((const char *)a, (const char *)b);
        case SYSCALL_close:
            return sys_fs_close(a);
        case SYSCALL_read:
            return sys_fs_read((char *)a, b, c);
        case SYSCALL_write:
            return sys_fs_write((const char *)a, b, c);
        case SYSCALL_window_create:
            return sys_window_create(a, b, c, d);
        case SYSCALL_window_set_border_color:
            return sys_set_border_color((const struct graphics_color *)a);
        case SYSCALL_window_draw_line:
            return sys_draw_line(a, b, c, d, (const struct graphics_color *)e);
        case SYSCALL_window_draw_arc:
            return sys_draw_arc(a, b, (const struct arc_info *)c, (const struct graphics_color *)d);
        case SYSCALL_window_draw_circle:
            return sys_draw_circle(a, b, (const double *)c, (const struct graphics_color *)d);
        case SYSCALL_window_draw_char:
            return sys_draw_char(a, b, (char)c, (const struct graphics_color *)d, (const struct graphics_color *)e);
        case SYSCALL_window_draw_string:
            return sys_draw_string(a, b, (const char *)c, (const struct graphics_color *)d, (const struct graphics_color *)e);
        default:
            return -1;
    }
}
