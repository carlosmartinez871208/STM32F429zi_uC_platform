MCAL_PATH = mcal
HAL_PATH  = hal
SERV_PATH = services
CDR_PATH  = complex_drivers

# Call makefiles within mcal.
define makemcalmodules
    for dir in $(MCAL_PATH)/*;\
        do\
        make -C $$dir $(1);\
        done
endef

# Call makefiles within hcal.
define makehalmodules
    for dir in $(HAL_PATH)/*;\
        do\
        make -C $$dir $(1);\
        done
endef

# Call makefiles within services.
define makemservmodules
    for dir in $(SERV_PATH)/*;\
        do\
        make -C $$dir $(1);\
        done
endef

# Call makefiles within complex drivers.
define makecdrmodules
    for dir in $(CDR_PATH)/*;\
        do\
        make -C $$dir $(1);\
        done
endef

all:
	@echo ''
	@echo "Building BSW ...!"
	@$(call makemcalmodules,all)
	@$(call makehalmodules,all)
	@$(call makecdrmodules,all)
	@$(call makemservmodules,all)

.PHONY: all