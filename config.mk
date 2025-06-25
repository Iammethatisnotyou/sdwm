VERSION = 0.11
CC = clang
WARNINGS = -Wall -Wextra -Wpedantic -Wshadow
CFLAGS = -std=c99 -O3 -O0
XORGFLAGS = -lX11
DEPFLAGS = -MP -MMD

SOURCE_DIR = src/
BUILD_DIR = build/
SOURCE := $(wildcard $(SOURCE_DIR)*.c)
OBJECTS := $(patsubst $(SOURCE_DIR)%.c, $(BUILD_DIR)%.o, $(SOURCE))
TARGET = sdwm

PREFIX = /usr/local
