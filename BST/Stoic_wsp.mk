.PHONY: clean All

All:
	@echo ----------Building project:[ Just - Debug ]----------
	@cd ".." && "$(MAKE)" -f "Just.mk"
clean:
	@echo ----------Cleaning project:[ Just - Debug ]----------
	@cd ".." && "$(MAKE)" -f "Just.mk" clean
