.PHONY: why3-init clean

all: Init.c.txt Confirmateur.c.txt AreTabSame.c.txt CopieTableau.c.txt SearchInTab.c.txt SearchInMat.c.txt

%.c.txt: %.c
	frama-c -wp $< -warn-signed-overflow -warn-unsigned-overflow -warn-signed-downcast -warn-unsigned-downcast -wp-prover alt-ergo -wp-report report_spec -wp-model caveat+real+cast -wp-extern-arrays -wp-extensional -wp-split -wp-report-basename $<

why3-init:
	why3 config detect

clean:
	rm -f *.c.txt