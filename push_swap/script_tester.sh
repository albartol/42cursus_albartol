#!/bin/bash

ejecutable="push_swap"
checker="checker"

max=20

DIR=script_cases

if [ ! -d "$DIR" ]; then
    mkdir "$DIR"
fi

if [ ! -e "$ejecutable" ]; then
    make
fi

if [ ! -e "$checker" ]; then
    make bonus
fi

for ((i=1; i<=max; i++)); do
    ARG=$(ruby -e "puts (-250..250).to_a.shuffle.join(' ')")
    OPER=$(./"$ejecutable" $ARG)
    NUM=$(echo "$OPER" | wc -l)
    echo "Caso $i:"
    echo "$NUM"
    echo "$OPER"| ./"$checker" $ARG
    echo "---------------"
    echo "$ARG" > $DIR/case$i
done

# for ((i=1; i<=max; i++)); do
#     ARG=$(ruby -e "puts (-250..250).to_a.shuffle.join(' ')")
#     OPER=$(./"$ejecutable" $ARG)
#     NUM=$(echo "$OPER" | wc -l)
#     echo "Caso $i:"
#     echo "$NUM"
#     echo "$OPER"| ./"$checker" $ARG
#     echo ""
#     echo "Números aleatorios generados: $ARG" > $DIR/case$i
#     echo "Número de oeraciones: $NUM" >> $DIR/case$i
#     echo "$OPER" >> $DIR/case$i
# done

# echo "Nueva prueba: ------------------------------------------" >> $DIR/script_log.txt
# echo "" >> $DIR/script_log.txt
# echo "$max casos" >> $DIR/script_log.txt
# echo "" >> $DIR/script_log.txt

# for ((i=1; i<=max; i++)); do
#     ARG=$(ruby -e "puts (-250..250).to_a.shuffle.join(' ')")
#     echo "Números aleatorios generados: $ARG" > $DIR/case$i
#     ./"$ejecutable" $ARG >> $DIR/case$i
#     echo "Caso $i:" >> $DIR/script_log.txt
#     cat $DIR/case$i | wc -l >> $DIR/script_log.txt
#     cat $DIR/case$i | grep -v "Números aleatorios generados: $ARG" | ./"$checker" $ARG >> $DIR/script_log.txt
#     echo "" >> $DIR/script_log.txt
# done

# cat $DIR/script_log.txt
