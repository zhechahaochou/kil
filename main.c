#include <stdio.h>

int main() {

    int count = 0;//参与人数
    int person[40] = {};
    int killNumber = 0;//死亡编号
    int deathFlag = -1;//代表死亡
    int deathCount = 0;//死亡人数
    int number = 0;//报数编号
    //确定人数
    printf("请输入参与的人数:");
    scanf("%d", &count);

    //立刻给每一个参与的人编号
    for (int i = 0; i < count; ++i) {
        person[i] = i + 1;
    }
//    for (int i = 0; i < count; ++i) {
//        printf("%d",person[i]);
//    }

    //确定出局编号
    printf("请输入出局编号:");
    scanf("%d", &killNumber);

    //开始游戏了

    for (int i = 0; i < count; i++) {
        //判断这个人是否活着
        if (person[i] != -1) {
            //需要报数
            number++;
            //检查是否报到死亡编号了
            if (number == killNumber) {
                //杀掉之前输出这个人的编号
                printf("%d ", person[i]);
                //杀掉这个人
                person[i] = -1;
                //重置
                number = 0;
                //杀掉的人数++
                deathCount++;
                //判断死亡人数
                if (deathCount == count - 1) {

                    for (int j = 0; j < count; ++j) {
                        if (person[j] != -1){
                            printf("幸存者是%d号\n", person[j]);
                            break;
                        }
                    }


                }
            }
        }

        //判断是否走到最后一个了
        if (i == count - 1) {
            //回到第一个
            i = -1;

        }

    }
    return 0;
}