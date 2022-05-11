# ----------------------------
# Makefile Options
# ----------------------------

NAME = Bloxxor
ICON = icon.png
DESCRIPTION = "Bloxxor"
COMPRESSED = NO
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)

