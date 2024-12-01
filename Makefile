INSTALL_DIR ?= $(PWD)/.install


PROG := esme-pwm-gpio12
SCRIPT := esme-pwm


OBJS := $(subst .c,.o, $(shell ls *.c))


all: $(PROG)

$(PROG): $(OBJS)

clean:
	-$(RM) -rf $(PROG) $(OBJS)

install:
	install -m 0755 -d $(INSTALL_DIR)/usr/bin
	install -m 0755 $(PROG) $(INSTALL_DIR)/usr/bin
	install -m 0755 -d $(INSTALL_DIR)/etc/init.d
	install -m 0755 $(SCRIPT) $(INSTALL_DIR)/etc/init.d

