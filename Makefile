KEYMAP_DIR=${QMK_HOME}/keyboards/planck/keymaps/cuderbot

.PHONY: build
build: link
	qmk compile -j4 -kb planck/rev6 -km cuderbot

.PHONY: link
link: unlink
	ln -sf "$(realpath keymap)" "${KEYMAP_DIR}"

.PHONY: unlink
unlink:
	rm -rf  "${KEYMAP_DIR}"

.PHONY: clean
clean: unlink
	qmk.sh clean