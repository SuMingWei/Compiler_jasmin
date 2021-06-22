.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
	ldc 0
	istore 0
	iload 0
	ldc 0
	istore 0
label0:
	iload 0
	ldc 10
	isub
	iflt label1
	iconst_0
	goto label2
label1:
	iconst_1
label2:
	ifeq label3
	goto label5
label4:
	iload 0
	ldc 1
	iadd
	istore 0
	goto label0
label5:
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	goto label4
label3:
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 0
	ldc 1
	istore 0
label6:
	iload 0
	ldc 0
	isub
	ifgt label7
	iconst_0
	goto label8
label7:
	iconst_1
label8:
	ifeq label9
	iload 0
	ldc 1
	isub
	istore 0
	ldc 3
	newarray int
	astore 1
	aload 1
	ldc 0
	ldc 1
	ldc 21
	iadd
	iastore
	aload 1
	ldc 1
	aload 1
	ldc 0
	iaload
	ldc 1
	isub
	iastore
	aload 1
	ldc 2
	aload 1
	ldc 1
	iaload
	ldc 3
	idiv
	iastore
	aload 1
	ldc 2
	iaload
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 3
	ldc 4
	ldc 5
	 
	ldc 8
	ineg
	iadd
	imul
	isub
	ldc 10
	ldc 7
	idiv
	isub
	ldc 4
	ineg
	ldc 3
	irem
	isub
	ifgt label10
	iconst_0
	goto label11
label10:
	iconst_1
label11:
	iconst_1
	iconst_1
	ixor
	iconst_0
	iconst_1
	ixor
	iconst_1
	ixor
	iand
	ior
	ifne label12
	ldc "false"
	goto label13
label12:
	ldc "true"
label13:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 3
	newarray float
	astore 2
	aload 2
	ldc 0
	ldc 1.100000
	ldc 2.100000
	fadd
	fastore
	aload 2
	ldc 0
	faload
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	goto label6
label9:
	ldc 0
	istore 3
	iload 3
	ldc 10
	iadd
	istore 3
label14:
	iload 3
	ldc 0
	isub
	ifgt label15
	iconst_0
	goto label16
label15:
	iconst_1
label16:
	ifeq label17
	iload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\t"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	ldc 1
	isub
	istore 3
	iload 3
	ldc 0
	isub
	ifne label18
	iconst_0
	goto label19
label18:
	iconst_1
label19:
	ifeq label20
	ldc 3.140000
	fstore 4
	fload 4
	f2i
	iload 3
	iadd
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	goto label21
label20:
	ldc 6.600000
	fstore 5
	ldc "If x == "
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	fload 5
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(F)V
label21:
	ldc 1
	istore 6
label22:
	iload 6
	ldc 3
	isub
	ifle label23
	iconst_0
	goto label24
label23:
	iconst_1
label24:
	ifeq label25
	ldc "\t"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "*"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 6
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "="
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	iload 6
	imul
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\t"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 6
	ldc 1
	iadd
	istore 6
	goto label22
label25:
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	goto label14
label17:
	return
.end method
