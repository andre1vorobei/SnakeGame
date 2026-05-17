BUILD_DIR=build

.PHONY: all cmake cmake_debug debug run clear help

all: cmake
	$(MAKE) -C $(BUILD_DIR)

debug: cmake_debug
	$(MAKE) -C $(BUILD_DIR)

cmake: 
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake $(CURDIR) -DCMAKE_BUILD_TYPE=Release

cmake_debug: 
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake $(CURDIR) -DCMAKE_BUILD_TYPE=Debug

run: 
	@./$(BUILD_DIR)/Snake

clean:
	@rm -rf $(BUILD_DIR)
