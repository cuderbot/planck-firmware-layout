KEYMAP_DIR=${QMK_HOME}/keyboards/planck/keymaps/cuderbot
OUTPUT_FILE=planck_rev6_cuderbot.bin

.PHONY: build
build: link
	qmk compile -j4 -kb planck/rev6 -km cuderbot
	mv "${QMK_HOME}/${OUTPUT_FILE}" ".build/${OUTPUT_FILE}"

.PHONY: link
link: unlink
	ln -sf "$(realpath keymap)" "${KEYMAP_DIR}"

.PHONY: unlink
unlink:
	rm -rf  "${KEYMAP_DIR}"

.PHONY: clean
clean: unlink
	qmk clean