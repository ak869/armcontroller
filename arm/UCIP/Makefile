#
#	MAKEFILE for uC/IP 1.0 Library
#
#	This makes the objects and links them into the library only.
#

# Choose the operating system.
IF_PATH = ./if_dev/ne2k
OS_PATH = ./OS_WIN32

TARGETNAME = UCIP.a

DEFS = -D_DEBUG 
INCLUDE = -I$(OS_PATH)

#CFLAGS = -I$(OS_PATH)
CC = gcc
CPPFLAGS = -O0 -g3 -W $(DEFS) $(INCLUDE)



#################################################
# List the dependancies for the targets to make

OBJECTS = \
       InetAddr.o \
       net.o \
       netaddrs.o \
       netarp.o \
       netauth.o \
       netbootp.o \
       netbuf.o \
       netchap.o \
       netchat.o \
       netchpms.o \
       netdebug.o \
       netdhcp.o \
       neteth.o \
       netether.o \
       netfsm.o \
       neticmp.o \
       netip.o \
       netipcp.o \
       netlcp.o \
       netmagic.o \
       netmd5.o \
       netpap.o \
       netppp.o \
       netrand.o \
       netsock.o \
       netsocka.o \
       nettcp.o \
       nettimer.o \
       netudp.o \
       netvj.o

#       netvj.o \
#       $(IF_PATH)/if_ne2kd.o \
#       $(IF_PATH)/if_os.o \
#       $(OS_PATH)/ucos.o \
#       $(OS_PATH)/ucos32.o \
#       $(OS_PATH)/trace.o


DEPENDENCIES = Makefile



#################################################
# How to build the targets

$(TARGETNAME): $(OBJECTS) $(DEPENDENCIES)
	$(RM) $(TARGETNAME)
	$(LD) -r $(OBJECTS) -o $(TARGETNAME)

#all:	$(NET_OBJS)
#	$(CC) $(NET_OBJS) -o $(OS_PATH)/ucip

.PHONY : clean



#################################################
# Cleanup

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGETNAME)
