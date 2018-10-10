.file    "code.s" 
    .option nopic 
    .text 
    .align    2 
    .globl    main 
    .type     main, @function 

main:                           # 
    j main2

main1:
    lui a0, 0xa4c5e             # 適当な数をつくり，1ビットずつ比較して分岐させることで
    ori a0, a0, 0x612           # 分岐予測器を間違えさせる

    lw t0, 0(t0)
    lw t0, 0(t0)

loop1:                          # ストアビットの動作検証：命令リカバリ時にストアビットがちゃんと降ろされるか確認
    lw t0, 0(t0)                # 適当に依存関係をつくり，ストアの発行を遅くする
    lw t0, 0(t0)
    lw t0, 0(t0)
    sw t1, 2(t0)                # IQ内に大量のストアが残るようにする．
    sw t1, 4(t0)
    sw t1, 6(t0)
    sw t1, 8(t0)
    sw t1, 10(t0)
    sw t1, 12(t0)
    sw t1, 14(t0)
    sw t1, 16(t0)
    sw t1, 18(t0)

    andi a1, a0, 0x1            # 下位1ビットを取得
    srli a0, a0, 0x1
    bne a1, zero, loop1          # 擬似ランダム分岐
    lw t0, 0(t0)                # ストアの発行を遅くする
    sw t1, 2(t0)                # 分岐予測ミスのリカバリ時にストアビットがちゃんと降ろされるか見る
    sw t1, 4(t0)
    sw t1, 6(t0)
    sw t1, 8(t0)
    sw t1, 10(t0)
    beq a0, zero, main2         # break
    j loop1
main2: 
    addi t0, zero, 0x0          # memory address 0 
    addi a0, zero, 0x0 
    addi a1, zero, 0x20         # loop num 32 
loop2:
    lw t0, 0x0(zero)
    sw zero, 0x0(t0)
    lw t1, 0x0(zero)
    lw t2, 0x100(zero)
    lw t3, 0x200(zero)
    addi a0, a0, 0x1
    beq a0, a1, main3
    j loop2
main3: 
    addi t0, zero, 0x0          # memory address 0 
    addi a0, zero, 0x0 
    addi a1, zero, 0x20         # loop num 32 
loop3:
    lw t0, 0x0(zero)
    sw zero, 0x0(t0)
    lw t1, 0x100(zero)
    lw t2, 0x0(zero)
    lw t3, 0x200(zero)
    addi a0, a0, 0x1
    beq a0, a1, main4
    j loop3
main4: 
    addi t0, zero, 0x0          # memory address 0 
    addi a0, zero, 0x0 
    addi a1, zero, 0x20         # loop num 32 
loop4:
    lw t0, 0x0(zero)
    sw zero, 0x0(t0)
    lw t1, 0x100(zero)
    lw t2, 0x100(zero)
    lw t3, 0x0(zero)
    addi a0, a0, 0x1
    beq a0, a1, output
    j loop4
output:
    li      t3, 0xf6fff070
    sw      x0, 0(t3)
    sw      x1, 0(t3)
    sw      x2, 0(t3)
    sw      x3, 0(t3)
    sw      x4, 0(t3)
    sw      x5, 0(t3)
    sw      x6, 0(t3)
    sw      x7, 0(t3)
    sw      x8, 0(t3)
    sw      x9, 0(t3)
    sw      x10, 0(t3)
    sw      x11, 0(t3)
    sw      x12, 0(t3)
    sw      x13, 0(t3)
    sw      x14, 0(t3)
    sw      x15, 0(t3)
    sw      x16, 0(t3)
    sw      x17, 0(t3)
    sw      x18, 0(t3)
    sw      x19, 0(t3)
    sw      x20, 0(t3)
    sw      x21, 0(t3)
    sw      x22, 0(t3)
    sw      x23, 0(t3)
    sw      x24, 0(t3)
    sw      x25, 0(t3)
    sw      x26, 0(t3)
    sw      x27, 0(t3)
    sw      x28, 0(t3)
    sw      x29, 0(t3)
    sw      x30, 0(t3)
    sw      x31, 0(t3)
main5: 
    j       main5                # ここでループして終了
