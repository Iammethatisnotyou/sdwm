include config.mk

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(XORGFLAGS) -o $@ $^

$(BUILD_DIR)%.o:$(SOURCE_DIR)%.c
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(DEPFLAGS) $(CFLAGS) $(WARNINGS) -o $@ $<
clean:
	rm -f $(TARGET) $(OBJECTS)

build: clean $(TARGET) $(OBJECTS) *.d

install:
	cp -f $(TARGET) $(PREFIX)/bin/$(TARGET)
	chmod 755 $(PREFIX)/bin/$(TARGET)
uninstall:
	rm -f $(PREFIX)/bin/$(TARGET)

.PHONY: all clean install uninstall build 
