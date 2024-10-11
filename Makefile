.PHONY: clean All

All:
	@echo "----------Building project:[ PECLRiofrioOrtegaRoberto - Debug ]----------"
	@cd "PECLRiofrioOrtegaRoberto" && "$(MAKE)" -f  "PECLRiofrioOrtegaRoberto.mk"
clean:
	@echo "----------Cleaning project:[ PECLRiofrioOrtegaRoberto - Debug ]----------"
	@cd "PECLRiofrioOrtegaRoberto" && "$(MAKE)" -f  "PECLRiofrioOrtegaRoberto.mk" clean
