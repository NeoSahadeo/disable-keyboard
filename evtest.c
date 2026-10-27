/* Blocks device specified
 * Usage: disable-keyboard [device]
 *
 * Example: disable-keyboard /dev/input/event0
 *
 * */

/*
 *  Copyright (c) 2026 Neo Sahadeo
 *  Copyright (c) 1999-2000 Vojtech Pavlik
 *  Copyright (c) 2009-2011 Red Hat, Inc
 */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * Should you need to contact me, the author, you can do so either by
 * e-mail - mail your message to <vojtech@ucw.cz>, or by paper mail:
 * Vojtech Pavlik, Simunkova 1594, Prague 8, 182 00 Czech Republic
 */

#include <linux/input.h>

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static volatile sig_atomic_t stop = 0;

void interrupt_handler(int s) {
  stop = 1;
}

int main(int argc, char** argv) {
  const char* device = NULL;

  if (optind < argc)
    device = argv[optind++];

  int fd;

  if ((fd = open(device, O_RDONLY)) < 0) {
    return 1;
  }

  if (!isatty(fileno(stdout)))
    setbuf(stdout, NULL);

  signal(SIGINT, interrupt_handler);
  signal(SIGTERM, interrupt_handler);

  ioctl(fd, EVIOCGRAB, (void*)1);

  while (!stop) {
    if (stop)
      break;
    sleep((unsigned int)-1);
  }

  ioctl(fd, EVIOCGRAB, (void*)0);
  return 0;
}
