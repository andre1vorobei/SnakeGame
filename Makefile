BUILD_DIR=build

.PHONY: all cmake clear help

all: cmake
	$(MAKE) -C $(BUILD_DIR)

cmake: 
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake $(CURDIR)

clean:
	@rm -rf $(BUILD_DIR)
