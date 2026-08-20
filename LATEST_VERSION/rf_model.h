// AUTO-GENERATED RANDOM FOREST MODEL
// Trained on: Aluminium, Copper, NonMetal, PreciousMetals, Steel
// Accuracy: 90.18%

#ifndef RF_MODEL_H
#define RF_MODEL_H

#include <stdint.h>

#include <string.h>
void add_vectors(double *v1, double *v2, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] + v2[i];
}
void mul_vector_number(double *v1, double num, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] * num;
}
void score(double * input, double * output) {
    double var0[5];
    double var1[5];
    double var2[5];
    double var3[5];
    double var4[5];
    double var5[5];
    double var6[5];
    double var7[5];
    double var8[5];
    double var9[5];
    double var10[5];
    double var11[5];
    double var12[5];
    double var13[5];
    double var14[5];
    double var15[5];
    double var16[5];
    double var17[5];
    double var18[5];
    double var19[5];
    double var20[5];
    double var21[5];
    double var22[5];
    double var23[5];
    double var24[5];
    double var25[5];
    double var26[5];
    double var27[5];
    double var28[5];
    double var29[5];
    double var30[5];
    if (input[0] <= 599.3500061035156) {
        if (input[1] <= 550.8500061035156) {
            if (input[2] <= 450.6499938964844) {
                if (input[2] <= 388.6999969482422) {
                    memcpy(var30, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[2] <= 418.34999084472656) {
                        memcpy(var30, (double[]){0.88, 0.0, 0.0, 0.0, 0.12}, 5 * sizeof(double));
                    } else {
                        memcpy(var30, (double[]){0.8024132730015083, 0.0, 0.0, 0.0, 0.1975867269984917}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 481.75) {
                    if (input[0] <= 461.4499969482422) {
                        memcpy(var30, (double[]){0.31654676258992803, 0.0, 0.0, 0.0, 0.6834532374100719}, 5 * sizeof(double));
                    } else {
                        memcpy(var30, (double[]){0.4870259481037924, 0.0, 0.0, 0.0, 0.5129740518962076}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 493.15000915527344) {
                        memcpy(var30, (double[]){0.11353711790393013, 0.0, 0.0, 0.0, 0.8864628820960698}, 5 * sizeof(double));
                    } else {
                        memcpy(var30, (double[]){0.08344459279038718, 0.0, 0.0, 0.1321762349799733, 0.7843791722296395}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 574.1000061035156) {
                if (input[1] <= 556.9499816894531) {
                    if (input[1] <= 553.75) {
                        memcpy(var30, (double[]){0.07772020725388602, 0.0, 0.0, 0.8341968911917099, 0.08808290155440415}, 5 * sizeof(double));
                    } else {
                        memcpy(var30, (double[]){0.37037037037037035, 0.0, 0.0, 0.43209876543209874, 0.19753086419753085}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 562.1499938964844) {
                        memcpy(var30, (double[]){0.028806584362139922, 0.0, 0.0, 0.9485596707818931, 0.022633744855967083}, 5 * sizeof(double));
                    } else {
                        memcpy(var30, (double[]){0.004739336492890996, 0.0, 0.0, 0.995260663507109, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 586.25) {
                    if (input[2] <= 577.6499938964844) {
                        memcpy(var30, (double[]){0.041666666666666664, 0.0, 0.0, 0.3125, 0.6458333333333334}, 5 * sizeof(double));
                    } else {
                        memcpy(var30, (double[]){0.11864406779661017, 0.0, 0.0, 0.615819209039548, 0.2655367231638418}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 587.1000061035156) {
                        memcpy(var30, (double[]){0.0, 0.0, 0.0, 0.75, 0.25}, 5 * sizeof(double));
                    } else {
                        memcpy(var30, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 657.8000183105469) {
            if (input[1] <= 616.3500061035156) {
                if (input[2] <= 610.9500122070312) {
                    if (input[2] <= 602.5499877929688) {
                        memcpy(var30, (double[]){0.0, 0.8602739726027397, 0.0, 0.13972602739726028, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var30, (double[]){0.0, 0.9438110749185668, 0.0, 0.05618892508143322, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 613.75) {
                        memcpy(var30, (double[]){0.0, 0.7058823529411765, 0.0, 0.29411764705882354, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var30, (double[]){0.0, 0.9428571428571428, 0.0, 0.05714285714285714, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 618.1499938964844) {
                    if (input[1] <= 618.0499877929688) {
                        memcpy(var30, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var30, (double[]){0.0, 0.75, 0.0, 0.25, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var30, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var30, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    double var31[5];
    if (input[2] <= 598.5499877929688) {
        if (input[2] <= 550.9499816894531) {
            if (input[2] <= 453.3500061035156) {
                if (input[2] <= 388.6000061035156) {
                    memcpy(var31, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[1] <= 396.15000915527344) {
                        memcpy(var31, (double[]){0.5569620253164557, 0.0, 0.0, 0.0, 0.4430379746835443}, 5 * sizeof(double));
                    } else {
                        memcpy(var31, (double[]){0.8426966292134831, 0.0, 0.0, 0.0, 0.15730337078651685}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 481.75) {
                    if (input[2] <= 462.5500030517578) {
                        memcpy(var31, (double[]){0.2689655172413793, 0.0, 0.0, 0.0, 0.7310344827586207}, 5 * sizeof(double));
                    } else {
                        memcpy(var31, (double[]){0.467680608365019, 0.0, 0.0, 0.0, 0.532319391634981}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 492.4499969482422) {
                        memcpy(var31, (double[]){0.1554054054054054, 0.0, 0.0, 0.0, 0.8445945945945946}, 5 * sizeof(double));
                    } else {
                        memcpy(var31, (double[]){0.07871321013004791, 0.0, 0.0, 0.13347022587268995, 0.7878165639972622}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 574.4500122070312) {
                if (input[1] <= 557.25) {
                    if (input[0] <= 554.4500122070312) {
                        memcpy(var31, (double[]){0.00641025641025641, 0.0, 0.0, 0.8525641025641025, 0.14102564102564102}, 5 * sizeof(double));
                    } else {
                        memcpy(var31, (double[]){0.2578125, 0.0, 0.0, 0.6015625, 0.140625}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 575.0500183105469) {
                        memcpy(var31, (double[]){0.02526315789473684, 0.0, 0.0, 0.9673684210526315, 0.007368421052631579}, 5 * sizeof(double));
                    } else {
                        memcpy(var31, (double[]){0.0, 0.0, 0.0, 0.0, 1.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 585.25) {
                    if (input[0] <= 578.0499877929688) {
                        memcpy(var31, (double[]){0.07142857142857142, 0.0, 0.0, 0.2857142857142857, 0.6428571428571429}, 5 * sizeof(double));
                    } else {
                        memcpy(var31, (double[]){0.13836477987421383, 0.0, 0.0, 0.6163522012578616, 0.24528301886792453}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 586.6999816894531) {
                        memcpy(var31, (double[]){0.0, 0.0, 0.0, 0.9166666666666666, 0.08333333333333333}, 5 * sizeof(double));
                    } else {
                        memcpy(var31, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 658.5) {
            if (input[0] <= 599.4500122070312) {
                if (input[2] <= 598.8000183105469) {
                    if (input[2] <= 598.6499938964844) {
                        memcpy(var31, (double[]){0.0, 0.5, 0.0, 0.5, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var31, (double[]){0.0, 0.2857142857142857, 0.0, 0.7142857142857143, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var31, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                }
            } else {
                if (input[1] <= 612.8500061035156) {
                    if (input[1] <= 612.25) {
                        memcpy(var31, (double[]){0.0, 0.9344159900062461, 0.0, 0.0655840099937539, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var31, (double[]){0.0, 0.3404255319148936, 0.0, 0.6595744680851063, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 617.25) {
                        memcpy(var31, (double[]){0.0, 0.967741935483871, 0.0, 0.03225806451612903, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var31, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            memcpy(var31, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var30, var31, 5, var29);
    double var32[5];
    if (input[1] <= 598.1999816894531) {
        if (input[1] <= 550.8500061035156) {
            if (input[1] <= 451.0) {
                if (input[0] <= 389.75) {
                    memcpy(var32, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[2] <= 395.5500030517578) {
                        memcpy(var32, (double[]){0.6197183098591549, 0.0, 0.0, 0.0, 0.38028169014084506}, 5 * sizeof(double));
                    } else {
                        memcpy(var32, (double[]){0.8380090497737557, 0.0, 0.0, 0.0, 0.16199095022624435}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 479.34999084472656) {
                    if (input[2] <= 457.65000915527344) {
                        memcpy(var32, (double[]){0.27722772277227725, 0.0, 0.0, 0.0, 0.7227722772277227}, 5 * sizeof(double));
                    } else {
                        memcpy(var32, (double[]){0.4400785854616896, 0.0, 0.0, 0.0, 0.5599214145383105}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.34999084472656) {
                        memcpy(var32, (double[]){0.1154639175257732, 0.0, 0.0, 0.0, 0.8845360824742268}, 5 * sizeof(double));
                    } else {
                        memcpy(var32, (double[]){0.08701563562202583, 0.0, 0.0, 0.12984364377974167, 0.7831407205982325}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 575.3500061035156) {
                if (input[1] <= 557.25) {
                    if (input[2] <= 553.75) {
                        memcpy(var32, (double[]){0.041884816753926704, 0.0, 0.0, 0.8167539267015707, 0.14136125654450263}, 5 * sizeof(double));
                    } else {
                        memcpy(var32, (double[]){0.2765957446808511, 0.0, 0.0, 0.5638297872340425, 0.1595744680851064}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 559.6499938964844) {
                        memcpy(var32, (double[]){0.019011406844106463, 0.0, 0.0, 0.9391634980988594, 0.04182509505703422}, 5 * sizeof(double));
                    } else {
                        memcpy(var32, (double[]){0.01272984441301273, 0.0, 0.0, 0.9872701555869873, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 585.5) {
                    if (input[0] <= 578.1499938964844) {
                        memcpy(var32, (double[]){0.06976744186046512, 0.0, 0.0, 0.23255813953488372, 0.6976744186046512}, 5 * sizeof(double));
                    } else {
                        memcpy(var32, (double[]){0.07792207792207792, 0.0, 0.0, 0.5974025974025974, 0.3246753246753247}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 586.6999816894531) {
                        memcpy(var32, (double[]){0.0, 0.0, 0.0, 0.9130434782608695, 0.08695652173913043}, 5 * sizeof(double));
                    } else {
                        memcpy(var32, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 657.8500061035156) {
            if (input[2] <= 617.5499877929688) {
                if (input[0] <= 599.3500061035156) {
                    memcpy(var32, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[1] <= 611.0499877929688) {
                        memcpy(var32, (double[]){0.0, 0.9196710942441493, 0.0, 0.08032890575585072, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var32, (double[]){0.0, 0.825925925925926, 0.0, 0.17407407407407408, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 618.9500122070312) {
                    if (input[0] <= 618.8500061035156) {
                        memcpy(var32, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var32, (double[]){0.0, 0.875, 0.0, 0.125, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var32, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var32, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var29, var32, 5, var28);
    double var33[5];
    if (input[2] <= 598.5499877929688) {
        if (input[1] <= 453.4499969482422) {
            if (input[0] <= 389.6499938964844) {
                memcpy(var33, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
            } else {
                if (input[0] <= 397.34999084472656) {
                    if (input[1] <= 390.25) {
                        memcpy(var33, (double[]){0.875, 0.0, 0.0, 0.0, 0.125}, 5 * sizeof(double));
                    } else {
                        memcpy(var33, (double[]){0.4576271186440678, 0.0, 0.0, 0.0, 0.5423728813559322}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 413.4499969482422) {
                        memcpy(var33, (double[]){0.9338842975206612, 0.0, 0.0, 0.0, 0.06611570247933884}, 5 * sizeof(double));
                    } else {
                        memcpy(var33, (double[]){0.7952941176470588, 0.0, 0.0, 0.0, 0.20470588235294118}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 550.8500061035156) {
                if (input[2] <= 480.4499969482422) {
                    if (input[0] <= 456.1999969482422) {
                        memcpy(var33, (double[]){0.0, 0.0, 0.0, 0.0, 1.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var33, (double[]){0.4121510673234811, 0.0, 0.0, 0.0, 0.5878489326765188}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.34999084472656) {
                        memcpy(var33, (double[]){0.10660980810234541, 0.0, 0.0, 0.0, 0.8933901918976546}, 5 * sizeof(double));
                    } else {
                        memcpy(var33, (double[]){0.07101449275362319, 0.0, 0.0, 0.14855072463768115, 0.7804347826086957}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 573.9500122070312) {
                    if (input[2] <= 557.0500183105469) {
                        memcpy(var33, (double[]){0.15789473684210525, 0.0, 0.0, 0.7157894736842105, 0.12631578947368421}, 5 * sizeof(double));
                    } else {
                        memcpy(var33, (double[]){0.021231422505307854, 0.0, 0.0, 0.9617834394904459, 0.016985138004246284}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 586.3999938964844) {
                        memcpy(var33, (double[]){0.08866995073891626, 0.0, 0.0, 0.5566502463054187, 0.35467980295566504}, 5 * sizeof(double));
                    } else {
                        memcpy(var33, (double[]){0.0, 0.0, 0.0, 0.9722222222222222, 0.027777777777777776}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 657.8500061035156) {
            if (input[2] <= 617.25) {
                if (input[1] <= 602.6499938964844) {
                    if (input[1] <= 598.1999816894531) {
                        memcpy(var33, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var33, (double[]){0.0, 0.8387909319899244, 0.0, 0.16120906801007556, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 610.4500122070312) {
                        memcpy(var33, (double[]){0.0, 0.9555757026291931, 0.0, 0.044424297370806894, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var33, (double[]){0.0, 0.8401084010840109, 0.0, 0.15989159891598917, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                memcpy(var33, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
            }
        } else {
            memcpy(var33, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var28, var33, 5, var27);
    double var34[5];
    if (input[2] <= 598.5499877929688) {
        if (input[1] <= 550.8500061035156) {
            if (input[0] <= 451.5500030517578) {
                if (input[0] <= 389.8000030517578) {
                    memcpy(var34, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[0] <= 397.34999084472656) {
                        memcpy(var34, (double[]){0.6170212765957447, 0.0, 0.0, 0.0, 0.3829787234042553}, 5 * sizeof(double));
                    } else {
                        memcpy(var34, (double[]){0.8346738159070599, 0.0, 0.0, 0.0, 0.16532618409294011}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 477.5500030517578) {
                    if (input[2] <= 462.5) {
                        memcpy(var34, (double[]){0.3076923076923077, 0.0, 0.0, 0.0, 0.6923076923076923}, 5 * sizeof(double));
                    } else {
                        memcpy(var34, (double[]){0.4770408163265306, 0.0, 0.0, 0.0, 0.5229591836734694}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 492.4499969482422) {
                        memcpy(var34, (double[]){0.1534090909090909, 0.0, 0.0, 0.0, 0.8465909090909091}, 5 * sizeof(double));
                    } else {
                        memcpy(var34, (double[]){0.08620689655172414, 0.0, 0.0, 0.13527851458885942, 0.7785145888594165}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 556.1000061035156) {
                if (input[0] <= 554.4500122070312) {
                    if (input[2] <= 552.0499877929688) {
                        memcpy(var34, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var34, (double[]){0.0, 0.0, 0.0, 0.8547008547008547, 0.1452991452991453}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 553.5499877929688) {
                        memcpy(var34, (double[]){0.7407407407407408, 0.0, 0.0, 0.1851851851851852, 0.07407407407407408}, 5 * sizeof(double));
                    } else {
                        memcpy(var34, (double[]){0.2533333333333334, 0.0, 0.0, 0.6666666666666667, 0.08000000000000002}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 574.0499877929688) {
                    if (input[2] <= 558.4500122070312) {
                        memcpy(var34, (double[]){0.03296703296703297, 0.0, 0.0, 0.8956043956043956, 0.07142857142857142}, 5 * sizeof(double));
                    } else {
                        memcpy(var34, (double[]){0.016270337922403004, 0.0, 0.0, 0.9824780976220275, 0.0012515644555694619}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 584.0499877929688) {
                        memcpy(var34, (double[]){0.13068181818181818, 0.0, 0.0, 0.5738636363636364, 0.29545454545454547}, 5 * sizeof(double));
                    } else {
                        memcpy(var34, (double[]){0.014018691588785047, 0.0, 0.0, 0.9672897196261683, 0.018691588785046728}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 658.1499938964844) {
            if (input[0] <= 599.4500122070312) {
                if (input[2] <= 598.75) {
                    if (input[2] <= 598.6499938964844) {
                        memcpy(var34, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var34, (double[]){0.0, 0.5, 0.0, 0.5, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var34, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                }
            } else {
                if (input[1] <= 612.8500061035156) {
                    if (input[1] <= 611.6499938964844) {
                        memcpy(var34, (double[]){0.0, 0.9276018099547512, 0.0, 0.07239819004524888, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var34, (double[]){0.0, 0.4482758620689655, 0.0, 0.5517241379310345, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 618.75) {
                        memcpy(var34, (double[]){0.0, 0.9714285714285714, 0.0, 0.02857142857142857, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var34, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            memcpy(var34, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var27, var34, 5, var26);
    double var35[5];
    if (input[1] <= 598.6499938964844) {
        if (input[1] <= 551.3500061035156) {
            if (input[1] <= 451.0) {
                if (input[1] <= 388.25) {
                    memcpy(var35, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[1] <= 396.6000061035156) {
                        memcpy(var35, (double[]){0.6506024096385542, 0.0, 0.0, 0.0, 0.3493975903614458}, 5 * sizeof(double));
                    } else {
                        memcpy(var35, (double[]){0.8395522388059702, 0.0, 0.0, 0.0, 0.16044776119402984}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 480.4499969482422) {
                    if (input[1] <= 472.5500030517578) {
                        memcpy(var35, (double[]){0.4589041095890411, 0.0, 0.0, 0.0, 0.541095890410959}, 5 * sizeof(double));
                    } else {
                        memcpy(var35, (double[]){0.31683168316831684, 0.0, 0.0, 0.0, 0.6831683168316832}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 493.15000915527344) {
                        memcpy(var35, (double[]){0.11572052401746726, 0.0, 0.0, 0.0, 0.8842794759825328}, 5 * sizeof(double));
                    } else {
                        memcpy(var35, (double[]){0.08808664259927798, 0.0, 0.0, 0.13646209386281588, 0.7754512635379062}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 573.9500122070312) {
                if (input[1] <= 556.8999938964844) {
                    if (input[0] <= 556.3500061035156) {
                        memcpy(var35, (double[]){0.08771929824561403, 0.0, 0.0, 0.7719298245614035, 0.14035087719298245}, 5 * sizeof(double));
                    } else {
                        memcpy(var35, (double[]){0.4666666666666667, 0.0, 0.0, 0.3333333333333333, 0.2}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 559.6499938964844) {
                        memcpy(var35, (double[]){0.012096774193548387, 0.0, 0.0, 0.9395161290322581, 0.04838709677419355}, 5 * sizeof(double));
                    } else {
                        memcpy(var35, (double[]){0.015827338129496403, 0.0, 0.0, 0.9841726618705036, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 585.1999816894531) {
                    if (input[0] <= 579.4500122070312) {
                        memcpy(var35, (double[]){0.023076923076923078, 0.0, 0.0, 0.5538461538461539, 0.4230769230769231}, 5 * sizeof(double));
                    } else {
                        memcpy(var35, (double[]){0.3076923076923077, 0.0, 0.0, 0.43956043956043955, 0.25274725274725274}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 598.1999816894531) {
                        memcpy(var35, (double[]){0.0, 0.0, 0.0, 0.9640718562874252, 0.03592814371257485}, 5 * sizeof(double));
                    } else {
                        memcpy(var35, (double[]){0.0, 0.35, 0.0, 0.65, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 657.9500122070312) {
            if (input[0] <= 599.5499877929688) {
                memcpy(var35, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
            } else {
                if (input[2] <= 613.5500183105469) {
                    if (input[2] <= 611.75) {
                        memcpy(var35, (double[]){0.0, 0.933572710951526, 0.0, 0.06642728904847396, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var35, (double[]){0.0, 0.5616438356164384, 0.0, 0.4383561643835616, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 615.8500061035156) {
                        memcpy(var35, (double[]){0.0, 0.968421052631579, 0.0, 0.031578947368421054, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var35, (double[]){0.0, 0.9993224932249323, 0.0, 0.0006775067750677507, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            memcpy(var35, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var26, var35, 5, var25);
    double var36[5];
    if (input[1] <= 598.1999816894531) {
        if (input[2] <= 551.3500061035156) {
            if (input[2] <= 451.15000915527344) {
                if (input[1] <= 388.1000061035156) {
                    memcpy(var36, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[2] <= 396.3999938964844) {
                        memcpy(var36, (double[]){0.5875, 0.0, 0.0, 0.0, 0.4125}, 5 * sizeof(double));
                    } else {
                        memcpy(var36, (double[]){0.8173913043478261, 0.0, 0.0, 0.0, 0.1826086956521739}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 479.9499969482422) {
                    if (input[1] <= 462.65000915527344) {
                        memcpy(var36, (double[]){0.2866666666666667, 0.0, 0.0, 0.0, 0.7133333333333334}, 5 * sizeof(double));
                    } else {
                        memcpy(var36, (double[]){0.47737556561085975, 0.0, 0.0, 0.0, 0.5226244343891403}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 492.25) {
                        memcpy(var36, (double[]){0.12577319587628866, 0.0, 0.0, 0.0, 0.8742268041237113}, 5 * sizeof(double));
                    } else {
                        memcpy(var36, (double[]){0.08545830461750517, 0.0, 0.0, 0.1536871123363198, 0.760854583046175}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 557.75) {
                if (input[0] <= 554.4500122070312) {
                    if (input[0] <= 554.0499877929688) {
                        memcpy(var36, (double[]){0.027522935779816515, 0.0, 0.0, 0.8715596330275229, 0.10091743119266056}, 5 * sizeof(double));
                    } else {
                        memcpy(var36, (double[]){0.0, 0.0, 0.0, 0.65625, 0.34375}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 556.3500061035156) {
                        memcpy(var36, (double[]){0.3380281690140845, 0.0, 0.0, 0.5492957746478874, 0.11267605633802817}, 5 * sizeof(double));
                    } else {
                        memcpy(var36, (double[]){0.6333333333333333, 0.0, 0.0, 0.3, 0.06666666666666667}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 574.3500061035156) {
                    if (input[0] <= 575.0500183105469) {
                        memcpy(var36, (double[]){0.01279317697228145, 0.0, 0.0, 0.9754797441364605, 0.011727078891257996}, 5 * sizeof(double));
                    } else {
                        memcpy(var36, (double[]){0.0, 0.0, 0.0, 0.0, 1.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 586.75) {
                        memcpy(var36, (double[]){0.0875, 0.0, 0.0, 0.6041666666666666, 0.30833333333333335}, 5 * sizeof(double));
                    } else {
                        memcpy(var36, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 658.6499938964844) {
            if (input[0] <= 599.4500122070312) {
                if (input[0] <= 599.3500061035156) {
                    memcpy(var36, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[1] <= 598.7999877929688) {
                        memcpy(var36, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var36, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 612.8500061035156) {
                    if (input[2] <= 612.0499877929688) {
                        memcpy(var36, (double[]){0.0, 0.9229334990677439, 0.0, 0.07706650093225606, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var36, (double[]){0.0, 0.44680851063829785, 0.0, 0.5531914893617021, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 617.5499877929688) {
                        memcpy(var36, (double[]){0.0, 0.9624413145539906, 0.0, 0.03755868544600939, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var36, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            memcpy(var36, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var25, var36, 5, var24);
    double var37[5];
    if (input[0] <= 599.3500061035156) {
        if (input[1] <= 451.15000915527344) {
            if (input[2] <= 389.0500030517578) {
                memcpy(var37, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
            } else {
                if (input[1] <= 396.6000061035156) {
                    if (input[0] <= 395.9499969482422) {
                        memcpy(var37, (double[]){0.7241379310344828, 0.0, 0.0, 0.0, 0.27586206896551724}, 5 * sizeof(double));
                    } else {
                        memcpy(var37, (double[]){0.2777777777777778, 0.0, 0.0, 0.0, 0.7222222222222222}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 429.84999084472656) {
                        memcpy(var37, (double[]){0.8259833134684148, 0.0, 0.0, 0.0, 0.17401668653158522}, 5 * sizeof(double));
                    } else {
                        memcpy(var37, (double[]){0.9311594202898551, 0.0, 0.0, 0.0, 0.06884057971014493}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 551.3500061035156) {
                if (input[1] <= 479.9499969482422) {
                    if (input[2] <= 455.34999084472656) {
                        memcpy(var37, (double[]){0.22807017543859648, 0.0, 0.0, 0.0, 0.7719298245614035}, 5 * sizeof(double));
                    } else {
                        memcpy(var37, (double[]){0.446843853820598, 0.0, 0.0, 0.0, 0.553156146179402}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.34999084472656) {
                        memcpy(var37, (double[]){0.10444444444444445, 0.0, 0.0, 0.0, 0.8955555555555555}, 5 * sizeof(double));
                    } else {
                        memcpy(var37, (double[]){0.08013698630136987, 0.0, 0.0, 0.13835616438356163, 0.7815068493150685}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 575.3500061035156) {
                    if (input[1] <= 557.25) {
                        memcpy(var37, (double[]){0.16279069767441862, 0.0, 0.0, 0.6976744186046512, 0.13953488372093023}, 5 * sizeof(double));
                    } else {
                        memcpy(var37, (double[]){0.012820512820512822, 0.0, 0.0, 0.9797008547008548, 0.00747863247863248}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 585.25) {
                        memcpy(var37, (double[]){0.10606060606060606, 0.0, 0.0, 0.45454545454545453, 0.4393939393939394}, 5 * sizeof(double));
                    } else {
                        memcpy(var37, (double[]){0.0, 0.0, 0.0, 0.9661016949152542, 0.03389830508474576}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 657.8000183105469) {
            if (input[0] <= 617.8999938964844) {
                if (input[2] <= 611.8500061035156) {
                    if (input[1] <= 602.6499938964844) {
                        memcpy(var37, (double[]){0.0, 0.8333333333333334, 0.0, 0.16666666666666666, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var37, (double[]){0.0, 0.9432950191570881, 0.0, 0.056704980842911874, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 613.75) {
                        memcpy(var37, (double[]){0.0, 0.47435897435897434, 0.0, 0.5256410256410257, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var37, (double[]){0.0, 0.9072847682119205, 0.0, 0.09271523178807947, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 618.75) {
                    if (input[2] <= 617.5499877929688) {
                        memcpy(var37, (double[]){0.0, 0.875, 0.0, 0.125, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var37, (double[]){0.0, 0.9871794871794872, 0.0, 0.01282051282051282, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var37, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var37, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var24, var37, 5, var23);
    double var38[5];
    if (input[2] <= 598.5499877929688) {
        if (input[1] <= 451.15000915527344) {
            if (input[0] <= 389.75) {
                memcpy(var38, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
            } else {
                if (input[0] <= 397.65000915527344) {
                    if (input[1] <= 393.5) {
                        memcpy(var38, (double[]){0.7058823529411765, 0.0, 0.0, 0.0, 0.29411764705882354}, 5 * sizeof(double));
                    } else {
                        memcpy(var38, (double[]){0.2727272727272727, 0.0, 0.0, 0.0, 0.7272727272727273}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 418.0500030517578) {
                        memcpy(var38, (double[]){0.8985849056603774, 0.0, 0.0, 0.0, 0.10141509433962265}, 5 * sizeof(double));
                    } else {
                        memcpy(var38, (double[]){0.7901990811638591, 0.0, 0.0, 0.0, 0.20980091883614088}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 551.3500061035156) {
                if (input[0] <= 481.25) {
                    if (input[1] <= 463.0500030517578) {
                        memcpy(var38, (double[]){0.2752808988764045, 0.0, 0.0, 0.0, 0.7247191011235955}, 5 * sizeof(double));
                    } else {
                        memcpy(var38, (double[]){0.4198645598194131, 0.0, 0.0, 0.0, 0.5801354401805869}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 493.4499969482422) {
                        memcpy(var38, (double[]){0.10222222222222223, 0.0, 0.0, 0.0, 0.8977777777777778}, 5 * sizeof(double));
                    } else {
                        memcpy(var38, (double[]){0.0845442536327609, 0.0, 0.0, 0.15587846763540292, 0.7595772787318362}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 575.2000122070312) {
                    if (input[0] <= 557.75) {
                        memcpy(var38, (double[]){0.13043478260869565, 0.0, 0.0, 0.7351778656126482, 0.13438735177865613}, 5 * sizeof(double));
                    } else {
                        memcpy(var38, (double[]){0.017726798748696558, 0.0, 0.0, 0.9687174139728885, 0.013555787278415016}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 585.5) {
                        memcpy(var38, (double[]){0.0794392523364486, 0.0, 0.0, 0.4953271028037383, 0.4252336448598131}, 5 * sizeof(double));
                    } else {
                        memcpy(var38, (double[]){0.0, 0.0, 0.0, 0.9887640449438202, 0.011235955056179775}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 657.8500061035156) {
            if (input[2] <= 615.4500122070312) {
                if (input[0] <= 599.4500122070312) {
                    if (input[0] <= 599.3500061035156) {
                        memcpy(var38, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var38, (double[]){0.0, 0.2, 0.0, 0.8, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 611.8500061035156) {
                        memcpy(var38, (double[]){0.0, 0.9246448424953675, 0.0, 0.0753551575046325, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var38, (double[]){0.0, 0.7721518987341772, 0.0, 0.22784810126582278, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 617.25) {
                    if (input[0] <= 617.75) {
                        memcpy(var38, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var38, (double[]){0.0, 0.8461538461538461, 0.0, 0.15384615384615385, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var38, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var38, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var23, var38, 5, var22);
    double var39[5];
    if (input[0] <= 599.4500122070312) {
        if (input[1] <= 550.8000183105469) {
            if (input[0] <= 451.5) {
                if (input[0] <= 389.75) {
                    memcpy(var39, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[2] <= 395.3000030517578) {
                        memcpy(var39, (double[]){0.6338028169014085, 0.0, 0.0, 0.0, 0.36619718309859156}, 5 * sizeof(double));
                    } else {
                        memcpy(var39, (double[]){0.8351254480286738, 0.0, 0.0, 0.0, 0.16487455197132617}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 480.84999084472656) {
                    if (input[0] <= 477.4499969482422) {
                        memcpy(var39, (double[]){0.4322820037105751, 0.0, 0.0, 0.0, 0.5677179962894249}, 5 * sizeof(double));
                    } else {
                        memcpy(var39, (double[]){0.27692307692307694, 0.0, 0.0, 0.0, 0.7230769230769231}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 493.3500061035156) {
                        memcpy(var39, (double[]){0.14782608695652175, 0.0, 0.0, 0.0, 0.8521739130434782}, 5 * sizeof(double));
                    } else {
                        memcpy(var39, (double[]){0.09009628610729023, 0.0, 0.0, 0.13686382393397525, 0.7730398899587345}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 575.0500183105469) {
                if (input[2] <= 557.0500183105469) {
                    if (input[2] <= 552.9500122070312) {
                        memcpy(var39, (double[]){0.008130081300813009, 0.0, 0.0, 0.9105691056910569, 0.08130081300813008}, 5 * sizeof(double));
                    } else {
                        memcpy(var39, (double[]){0.304635761589404, 0.0, 0.0, 0.5496688741721855, 0.1456953642384106}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 558.75) {
                        memcpy(var39, (double[]){0.004830917874396135, 0.0, 0.0, 0.9371980676328503, 0.057971014492753624}, 5 * sizeof(double));
                    } else {
                        memcpy(var39, (double[]){0.02077922077922078, 0.0, 0.0, 0.9792207792207792, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 584.0499877929688) {
                    if (input[1] <= 577.8000183105469) {
                        memcpy(var39, (double[]){0.0, 0.0, 0.0, 0.2826086956521739, 0.717391304347826}, 5 * sizeof(double));
                    } else {
                        memcpy(var39, (double[]){0.11403508771929824, 0.0, 0.0, 0.5789473684210527, 0.30701754385964913}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 583.3500061035156) {
                        memcpy(var39, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var39, (double[]){0.0, 0.004132231404958678, 0.0, 0.9545454545454546, 0.04132231404958678}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 657.7000122070312) {
            if (input[0] <= 615.3500061035156) {
                if (input[1] <= 611.75) {
                    if (input[2] <= 602.25) {
                        memcpy(var39, (double[]){0.0, 0.8593272171253823, 0.0, 0.14067278287461774, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var39, (double[]){0.0, 0.93984375, 0.0, 0.06015625, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 613.75) {
                        memcpy(var39, (double[]){0.0, 0.5853658536585366, 0.0, 0.4146341463414634, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var39, (double[]){0.0, 0.9473684210526315, 0.0, 0.05263157894736842, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 618.9500122070312) {
                    if (input[2] <= 618.6000061035156) {
                        memcpy(var39, (double[]){0.0, 0.9722222222222222, 0.0, 0.027777777777777776, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var39, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var39, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var39, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var22, var39, 5, var21);
    double var40[5];
    if (input[0] <= 599.3500061035156) {
        if (input[2] <= 550.75) {
            if (input[0] <= 451.5) {
                if (input[2] <= 388.65000915527344) {
                    memcpy(var40, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[2] <= 396.0500030517578) {
                        memcpy(var40, (double[]){0.6, 0.0, 0.0, 0.0, 0.4}, 5 * sizeof(double));
                    } else {
                        memcpy(var40, (double[]){0.8507209499575912, 0.0, 0.0, 0.0, 0.14927905004240882}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 477.5500030517578) {
                    if (input[1] <= 464.4499969482422) {
                        memcpy(var40, (double[]){0.29411764705882354, 0.0, 0.0, 0.0, 0.7058823529411765}, 5 * sizeof(double));
                    } else {
                        memcpy(var40, (double[]){0.45125348189415043, 0.0, 0.0, 0.0, 0.5487465181058496}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 492.9499969482422) {
                        memcpy(var40, (double[]){0.12734082397003746, 0.0, 0.0, 0.0, 0.8726591760299626}, 5 * sizeof(double));
                    } else {
                        memcpy(var40, (double[]){0.07692307692307693, 0.0, 0.0, 0.13299784327821712, 0.790079079798706}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 575.3500061035156) {
                if (input[0] <= 557.6499938964844) {
                    if (input[2] <= 552.9500122070312) {
                        memcpy(var40, (double[]){0.01834862385321101, 0.0, 0.0, 0.8899082568807339, 0.09174311926605505}, 5 * sizeof(double));
                    } else {
                        memcpy(var40, (double[]){0.2826086956521739, 0.0, 0.0, 0.5869565217391305, 0.13043478260869565}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 563.0) {
                        memcpy(var40, (double[]){0.024955436720142606, 0.0, 0.0, 0.9590017825311944, 0.016042780748663107}, 5 * sizeof(double));
                    } else {
                        memcpy(var40, (double[]){0.002242152466367713, 0.0, 0.0, 0.9977578475336323, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 585.9499816894531) {
                    if (input[0] <= 578.4500122070312) {
                        memcpy(var40, (double[]){0.1, 0.0, 0.0, 0.3, 0.6}, 5 * sizeof(double));
                    } else {
                        memcpy(var40, (double[]){0.08982035928143713, 0.0, 0.0, 0.6526946107784432, 0.25748502994011974}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 586.6499938964844) {
                        memcpy(var40, (double[]){0.0, 0.0, 0.0, 0.7142857142857143, 0.2857142857142857}, 5 * sizeof(double));
                    } else {
                        memcpy(var40, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 658.6499938964844) {
            if (input[0] <= 613.75) {
                if (input[0] <= 612.8000183105469) {
                    if (input[2] <= 601.6499938964844) {
                        memcpy(var40, (double[]){0.0, 0.8811188811188811, 0.0, 0.11888111888111888, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var40, (double[]){0.0, 0.9410496046010065, 0.0, 0.05895039539899353, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 612.9500122070312) {
                        memcpy(var40, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var40, (double[]){0.0, 0.46153846153846156, 0.0, 0.5384615384615384, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 617.5499877929688) {
                    if (input[1] <= 617.8499755859375) {
                        memcpy(var40, (double[]){0.0, 0.968944099378882, 0.0, 0.031055900621118012, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var40, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var40, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var40, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var21, var40, 5, var20);
    double var41[5];
    if (input[2] <= 598.5) {
        if (input[1] <= 471.65000915527344) {
            if (input[0] <= 451.5500030517578) {
                if (input[1] <= 388.1000061035156) {
                    memcpy(var41, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[2] <= 395.5) {
                        memcpy(var41, (double[]){0.6585365853658537, 0.0, 0.0, 0.0, 0.34146341463414637}, 5 * sizeof(double));
                    } else {
                        memcpy(var41, (double[]){0.8467274233637117, 0.0, 0.0, 0.0, 0.15327257663628832}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 469.34999084472656) {
                    if (input[2] <= 455.34999084472656) {
                        memcpy(var41, (double[]){0.2553191489361702, 0.0, 0.0, 0.0, 0.7446808510638298}, 5 * sizeof(double));
                    } else {
                        memcpy(var41, (double[]){0.5017182130584192, 0.0, 0.0, 0.0, 0.49828178694158076}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 470.75) {
                        memcpy(var41, (double[]){0.7142857142857143, 0.0, 0.0, 0.0, 0.2857142857142857}, 5 * sizeof(double));
                    } else {
                        memcpy(var41, (double[]){0.8947368421052632, 0.0, 0.0, 0.0, 0.10526315789473684}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 552.25) {
                if (input[2] <= 480.5) {
                    if (input[1] <= 478.3999938964844) {
                        memcpy(var41, (double[]){0.28901734104046245, 0.0, 0.0, 0.0, 0.7109826589595376}, 5 * sizeof(double));
                    } else {
                        memcpy(var41, (double[]){0.5319148936170213, 0.0, 0.0, 0.0, 0.46808510638297873}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 492.65000915527344) {
                        memcpy(var41, (double[]){0.12840466926070038, 0.0, 0.0, 0.0, 0.8715953307392996}, 5 * sizeof(double));
                    } else {
                        memcpy(var41, (double[]){0.07581967213114754, 0.0, 0.0, 0.13934426229508196, 0.7848360655737705}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 573.9500122070312) {
                    if (input[2] <= 556.5500183105469) {
                        memcpy(var41, (double[]){0.13333333333333333, 0.0, 0.0, 0.7846153846153846, 0.08205128205128205}, 5 * sizeof(double));
                    } else {
                        memcpy(var41, (double[]){0.019313304721030045, 0.0, 0.0, 0.9753218884120172, 0.00536480686695279}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 585.1999816894531) {
                        memcpy(var41, (double[]){0.10628019323671498, 0.0, 0.0, 0.5942028985507246, 0.2995169082125604}, 5 * sizeof(double));
                    } else {
                        memcpy(var41, (double[]){0.0, 0.0, 0.0, 0.9810126582278481, 0.0189873417721519}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 657.8500061035156) {
            if (input[1] <= 617.25) {
                if (input[2] <= 610.9500122070312) {
                    if (input[2] <= 602.5499877929688) {
                        memcpy(var41, (double[]){0.0, 0.8621553884711779, 0.0, 0.13784461152882205, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var41, (double[]){0.0, 0.9534510433386838, 0.0, 0.04654895666131621, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 613.75) {
                        memcpy(var41, (double[]){0.0, 0.6198347107438017, 0.0, 0.38016528925619836, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var41, (double[]){0.0, 0.9481481481481482, 0.0, 0.05185185185185185, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 618.75) {
                    if (input[1] <= 618.6499938964844) {
                        memcpy(var41, (double[]){0.0, 0.9861111111111112, 0.0, 0.013888888888888888, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var41, (double[]){0.0, 0.8333333333333334, 0.0, 0.16666666666666666, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var41, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var41, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var20, var41, 5, var19);
    double var42[5];
    if (input[2] <= 598.5499877929688) {
        if (input[0] <= 552.25) {
            if (input[0] <= 448.5500030517578) {
                if (input[1] <= 388.1000061035156) {
                    memcpy(var42, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[1] <= 397.4499969482422) {
                        memcpy(var42, (double[]){0.5454545454545454, 0.0, 0.0, 0.0, 0.45454545454545453}, 5 * sizeof(double));
                    } else {
                        memcpy(var42, (double[]){0.8313796212804329, 0.0, 0.0, 0.0, 0.16862037871956717}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 479.84999084472656) {
                    if (input[1] <= 478.9499969482422) {
                        memcpy(var42, (double[]){0.4258064516129032, 0.0, 0.0, 0.0, 0.5741935483870968}, 5 * sizeof(double));
                    } else {
                        memcpy(var42, (double[]){0.85, 0.0, 0.0, 0.0, 0.15}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 492.25) {
                        memcpy(var42, (double[]){0.1279317697228145, 0.0, 0.0, 0.0, 0.8720682302771855}, 5 * sizeof(double));
                    } else {
                        memcpy(var42, (double[]){0.08040201005025126, 0.0, 0.0, 0.15793251974156497, 0.7616654702081838}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 575.2000122070312) {
                if (input[2] <= 557.1000061035156) {
                    if (input[0] <= 554.4500122070312) {
                        memcpy(var42, (double[]){0.008849557522123894, 0.0, 0.0, 0.8495575221238938, 0.1415929203539823}, 5 * sizeof(double));
                    } else {
                        memcpy(var42, (double[]){0.3953488372093023, 0.0, 0.0, 0.5271317829457365, 0.07751937984496124}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 558.75) {
                        memcpy(var42, (double[]){0.004132231404958678, 0.0, 0.0, 0.9380165289256198, 0.05785123966942149}, 5 * sizeof(double));
                    } else {
                        memcpy(var42, (double[]){0.014084507042253521, 0.0, 0.0, 0.9859154929577465, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 586.3500061035156) {
                    if (input[1] <= 577.9500122070312) {
                        memcpy(var42, (double[]){0.03333333333333333, 0.0, 0.0, 0.26666666666666666, 0.7}, 5 * sizeof(double));
                    } else {
                        memcpy(var42, (double[]){0.08284023668639054, 0.0, 0.0, 0.6035502958579881, 0.3136094674556213}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var42, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                }
            }
        }
    } else {
        if (input[1] <= 657.5500183105469) {
            if (input[2] <= 600.5499877929688) {
                if (input[2] <= 600.4500122070312) {
                    if (input[2] <= 599.3500061035156) {
                        memcpy(var42, (double[]){0.0, 0.7966101694915254, 0.0, 0.2033898305084746, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var42, (double[]){0.0, 0.6792452830188679, 0.0, 0.32075471698113206, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var42, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                }
            } else {
                if (input[0] <= 619.0) {
                    if (input[1] <= 618.0499877929688) {
                        memcpy(var42, (double[]){0.0, 0.9273273273273274, 0.0, 0.07267267267267268, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var42, (double[]){0.0, 0.5714285714285714, 0.0, 0.42857142857142855, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var42, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var42, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var19, var42, 5, var18);
    double var43[5];
    if (input[2] <= 598.5499877929688) {
        if (input[0] <= 454.5500030517578) {
            if (input[1] <= 389.25) {
                memcpy(var43, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
            } else {
                if (input[0] <= 397.34999084472656) {
                    if (input[1] <= 395.5) {
                        memcpy(var43, (double[]){0.6470588235294118, 0.0, 0.0, 0.0, 0.35294117647058826}, 5 * sizeof(double));
                    } else {
                        memcpy(var43, (double[]){0.2857142857142857, 0.0, 0.0, 0.0, 0.7142857142857143}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 450.5) {
                        memcpy(var43, (double[]){0.8446428571428571, 0.0, 0.0, 0.0, 0.15535714285714286}, 5 * sizeof(double));
                    } else {
                        memcpy(var43, (double[]){0.5142857142857142, 0.0, 0.0, 0.0, 0.4857142857142857}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 552.3000183105469) {
                if (input[1] <= 480.5500030517578) {
                    if (input[2] <= 461.0500030517578) {
                        memcpy(var43, (double[]){0.22522522522522523, 0.0, 0.0, 0.0, 0.7747747747747747}, 5 * sizeof(double));
                    } else {
                        memcpy(var43, (double[]){0.4417293233082707, 0.0, 0.0, 0.0, 0.5582706766917294}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 493.15000915527344) {
                        memcpy(var43, (double[]){0.11777777777777777, 0.0, 0.0, 0.0, 0.8822222222222222}, 5 * sizeof(double));
                    } else {
                        memcpy(var43, (double[]){0.09121621621621621, 0.0, 0.0, 0.13986486486486485, 0.768918918918919}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 575.3500061035156) {
                    if (input[0] <= 557.6999816894531) {
                        memcpy(var43, (double[]){0.15384615384615385, 0.0, 0.0, 0.7530364372469636, 0.0931174089068826}, 5 * sizeof(double));
                    } else {
                        memcpy(var43, (double[]){0.016648168701442843, 0.0, 0.0, 0.9755826859045506, 0.00776914539400666}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 583.5) {
                        memcpy(var43, (double[]){0.1111111111111111, 0.0, 0.0, 0.4708994708994709, 0.41798941798941797}, 5 * sizeof(double));
                    } else {
                        memcpy(var43, (double[]){0.0, 0.0, 0.0, 0.9664804469273743, 0.0335195530726257}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 658.6499938964844) {
            if (input[0] <= 599.4500122070312) {
                if (input[0] <= 599.3500061035156) {
                    memcpy(var43, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[2] <= 598.7999877929688) {
                        memcpy(var43, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var43, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 617.5499877929688) {
                    if (input[0] <= 611.0499877929688) {
                        memcpy(var43, (double[]){0.0, 0.9308671922377199, 0.0, 0.06913280776228017, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var43, (double[]){0.0, 0.8471760797342193, 0.0, 0.15282392026578073, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var43, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var43, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var18, var43, 5, var17);
    double var44[5];
    if (input[1] <= 598.1999816894531) {
        if (input[1] <= 550.8500061035156) {
            if (input[0] <= 454.6499938964844) {
                if (input[1] <= 388.1000061035156) {
                    memcpy(var44, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[1] <= 451.15000915527344) {
                        memcpy(var44, (double[]){0.8293683347005743, 0.0, 0.0, 0.0, 0.17063166529942575}, 5 * sizeof(double));
                    } else {
                        memcpy(var44, (double[]){0.5588235294117647, 0.0, 0.0, 0.0, 0.4411764705882353}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 479.75) {
                    if (input[2] <= 462.4499969482422) {
                        memcpy(var44, (double[]){0.27007299270072993, 0.0, 0.0, 0.0, 0.7299270072992701}, 5 * sizeof(double));
                    } else {
                        memcpy(var44, (double[]){0.4896265560165975, 0.0, 0.0, 0.0, 0.5103734439834025}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.34999084472656) {
                        memcpy(var44, (double[]){0.12601626016260162, 0.0, 0.0, 0.0, 0.8739837398373984}, 5 * sizeof(double));
                    } else {
                        memcpy(var44, (double[]){0.08327550312283137, 0.0, 0.0, 0.14018043025676613, 0.7765440666204025}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 574.8000183105469) {
                if (input[0] <= 557.75) {
                    if (input[0] <= 556.3500061035156) {
                        memcpy(var44, (double[]){0.07731958762886598, 0.0, 0.0, 0.8402061855670103, 0.08247422680412371}, 5 * sizeof(double));
                    } else {
                        memcpy(var44, (double[]){0.5483870967741936, 0.0, 0.0, 0.32258064516129037, 0.12903225806451615}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 557.0499877929688) {
                        memcpy(var44, (double[]){0.0, 0.0, 0.0, 0.0, 1.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var44, (double[]){0.017797552836484983, 0.0, 0.0, 0.9766407119021134, 0.0055617352614015575}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 584.4500122070312) {
                    if (input[2] <= 577.5499877929688) {
                        memcpy(var44, (double[]){0.0, 0.0, 0.0, 0.26666666666666666, 0.7333333333333333}, 5 * sizeof(double));
                    } else {
                        memcpy(var44, (double[]){0.1640625, 0.0, 0.0, 0.5859375, 0.25}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 586.75) {
                        memcpy(var44, (double[]){0.0, 0.0, 0.0, 0.825, 0.175}, 5 * sizeof(double));
                    } else {
                        memcpy(var44, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 657.8500061035156) {
            if (input[0] <= 599.4500122070312) {
                if (input[1] <= 598.5499877929688) {
                    if (input[2] <= 598.6499938964844) {
                        memcpy(var44, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var44, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 599.3500061035156) {
                        memcpy(var44, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var44, (double[]){0.0, 0.25, 0.0, 0.75, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 617.25) {
                    if (input[0] <= 612.25) {
                        memcpy(var44, (double[]){0.0, 0.9345057610673135, 0.0, 0.06549423893268648, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var44, (double[]){0.0, 0.7867298578199052, 0.0, 0.2132701421800948, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var44, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var44, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var17, var44, 5, var16);
    double var45[5];
    if (input[1] <= 598.1999816894531) {
        if (input[2] <= 453.3000030517578) {
            if (input[0] <= 389.75) {
                memcpy(var45, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
            } else {
                if (input[2] <= 396.0500030517578) {
                    if (input[0] <= 395.9499969482422) {
                        memcpy(var45, (double[]){0.6724137931034483, 0.0, 0.0, 0.0, 0.3275862068965517}, 5 * sizeof(double));
                    } else {
                        memcpy(var45, (double[]){0.3333333333333333, 0.0, 0.0, 0.0, 0.6666666666666666}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 418.34999084472656) {
                        memcpy(var45, (double[]){0.8980477223427332, 0.0, 0.0, 0.0, 0.1019522776572668}, 5 * sizeof(double));
                    } else {
                        memcpy(var45, (double[]){0.7929078014184398, 0.0, 0.0, 0.0, 0.20709219858156028}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 551.3999938964844) {
                if (input[0] <= 481.65000915527344) {
                    if (input[1] <= 461.95001220703125) {
                        memcpy(var45, (double[]){0.20535714285714285, 0.0, 0.0, 0.0, 0.7946428571428571}, 5 * sizeof(double));
                    } else {
                        memcpy(var45, (double[]){0.4045643153526971, 0.0, 0.0, 0.0, 0.5954356846473029}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.4499969482422) {
                        memcpy(var45, (double[]){0.10367170626349892, 0.0, 0.0, 0.0, 0.896328293736501}, 5 * sizeof(double));
                    } else {
                        memcpy(var45, (double[]){0.07012811867835468, 0.0, 0.0, 0.1260957518543493, 0.803776129467296}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 557.75) {
                    if (input[1] <= 553.75) {
                        memcpy(var45, (double[]){0.1, 0.0, 0.0, 0.7666666666666667, 0.13333333333333333}, 5 * sizeof(double));
                    } else {
                        memcpy(var45, (double[]){0.39759036144578314, 0.0, 0.0, 0.40963855421686746, 0.1927710843373494}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 575.3500061035156) {
                        memcpy(var45, (double[]){0.011591148577449948, 0.0, 0.0, 0.9810326659641728, 0.007376185458377239}, 5 * sizeof(double));
                    } else {
                        memcpy(var45, (double[]){0.04699738903394256, 0.0, 0.0, 0.7232375979112271, 0.2297650130548303}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 658.6499938964844) {
            if (input[1] <= 613.75) {
                if (input[0] <= 599.4500122070312) {
                    memcpy(var45, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[1] <= 610.9500122070312) {
                        memcpy(var45, (double[]){0.0, 0.9250960307298336, 0.0, 0.07490396927016646, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var45, (double[]){0.0, 0.6444444444444445, 0.0, 0.35555555555555557, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 618.75) {
                    if (input[1] <= 618.6499938964844) {
                        memcpy(var45, (double[]){0.0, 0.978494623655914, 0.0, 0.021505376344086023, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var45, (double[]){0.0, 0.3333333333333333, 0.0, 0.6666666666666666, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var45, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var45, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var16, var45, 5, var15);
    double var46[5];
    if (input[0] <= 599.3500061035156) {
        if (input[2] <= 550.9499816894531) {
            if (input[2] <= 450.84999084472656) {
                if (input[2] <= 388.6999969482422) {
                    memcpy(var46, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[1] <= 396.15000915527344) {
                        memcpy(var46, (double[]){0.5764705882352941, 0.0, 0.0, 0.0, 0.4235294117647059}, 5 * sizeof(double));
                    } else {
                        memcpy(var46, (double[]){0.8393645189761695, 0.0, 0.0, 0.0, 0.16063548102383055}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 479.75) {
                    if (input[1] <= 457.84999084472656) {
                        memcpy(var46, (double[]){0.3153153153153153, 0.0, 0.0, 0.0, 0.6846846846846847}, 5 * sizeof(double));
                    } else {
                        memcpy(var46, (double[]){0.47058823529411764, 0.0, 0.0, 0.0, 0.5294117647058824}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.5500030517578) {
                        memcpy(var46, (double[]){0.14149139579349904, 0.0, 0.0, 0.0, 0.858508604206501}, 5 * sizeof(double));
                    } else {
                        memcpy(var46, (double[]){0.0809688581314879, 0.0, 0.0, 0.14602076124567473, 0.7730103806228373}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 575.3500061035156) {
                if (input[0] <= 557.6499938964844) {
                    if (input[2] <= 553.0499877929688) {
                        memcpy(var46, (double[]){0.010526315789473684, 0.0, 0.0, 0.8526315789473684, 0.1368421052631579}, 5 * sizeof(double));
                    } else {
                        memcpy(var46, (double[]){0.28169014084507044, 0.0, 0.0, 0.5774647887323944, 0.14084507042253522}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 557.25) {
                        memcpy(var46, (double[]){0.0, 0.0, 0.0, 0.3333333333333333, 0.6666666666666666}, 5 * sizeof(double));
                    } else {
                        memcpy(var46, (double[]){0.021367521367521368, 0.0, 0.0, 0.969017094017094, 0.009615384615384616}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 585.75) {
                    if (input[2] <= 577.6000061035156) {
                        memcpy(var46, (double[]){0.075, 0.0, 0.0, 0.15, 0.775}, 5 * sizeof(double));
                    } else {
                        memcpy(var46, (double[]){0.11392405063291139, 0.0, 0.0, 0.6139240506329114, 0.2721518987341772}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 586.5) {
                        memcpy(var46, (double[]){0.0, 0.0, 0.0, 0.8181818181818182, 0.18181818181818182}, 5 * sizeof(double));
                    } else {
                        memcpy(var46, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 658.6499938964844) {
            if (input[0] <= 617.0499877929688) {
                if (input[0] <= 611.0499877929688) {
                    if (input[0] <= 603.1499938964844) {
                        memcpy(var46, (double[]){0.0, 0.8771929824561403, 0.0, 0.12280701754385964, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var46, (double[]){0.0, 0.9510603588907015, 0.0, 0.048939641109298535, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 612.6499938964844) {
                        memcpy(var46, (double[]){0.0, 0.6904761904761905, 0.0, 0.30952380952380953, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var46, (double[]){0.0, 0.9271523178807947, 0.0, 0.0728476821192053, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 618.9500122070312) {
                    if (input[1] <= 618.5) {
                        memcpy(var46, (double[]){0.0, 0.9746835443037974, 0.0, 0.02531645569620253, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var46, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var46, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var46, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var15, var46, 5, var14);
    double var47[5];
    if (input[0] <= 599.3500061035156) {
        if (input[1] <= 551.1999816894531) {
            if (input[1] <= 451.15000915527344) {
                if (input[0] <= 389.6499938964844) {
                    memcpy(var47, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[2] <= 395.8999938964844) {
                        memcpy(var47, (double[]){0.6436781609195402, 0.0, 0.0, 0.0, 0.3563218390804598}, 5 * sizeof(double));
                    } else {
                        memcpy(var47, (double[]){0.8382608695652174, 0.0, 0.0, 0.0, 0.1617391304347826}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 478.65000915527344) {
                    if (input[0] <= 453.1999969482422) {
                        memcpy(var47, (double[]){0.0, 0.0, 0.0, 0.0, 1.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var47, (double[]){0.4250871080139373, 0.0, 0.0, 0.0, 0.5749128919860628}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 492.4499969482422) {
                        memcpy(var47, (double[]){0.13655462184873948, 0.0, 0.0, 0.0, 0.8634453781512605}, 5 * sizeof(double));
                    } else {
                        memcpy(var47, (double[]){0.07142857142857142, 0.0, 0.0, 0.13366336633663367, 0.7949080622347949}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 574.1000061035156) {
                if (input[2] <= 557.0500183105469) {
                    if (input[2] <= 552.25) {
                        memcpy(var47, (double[]){0.0, 0.0, 0.0, 0.9574468085106383, 0.0425531914893617}, 5 * sizeof(double));
                    } else {
                        memcpy(var47, (double[]){0.29239766081871343, 0.0, 0.0, 0.5555555555555556, 0.15204678362573099}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 561.3500061035156) {
                        memcpy(var47, (double[]){0.02868852459016394, 0.0, 0.0, 0.9672131147540984, 0.004098360655737706}, 5 * sizeof(double));
                    } else {
                        memcpy(var47, (double[]){0.004201680672268907, 0.0, 0.0, 0.9957983193277311, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 584.0) {
                    if (input[0] <= 582.1000061035156) {
                        memcpy(var47, (double[]){0.0425531914893617, 0.0, 0.0, 0.5319148936170213, 0.425531914893617}, 5 * sizeof(double));
                    } else {
                        memcpy(var47, (double[]){0.56, 0.0, 0.0, 0.28, 0.16}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 586.75) {
                        memcpy(var47, (double[]){0.0, 0.0, 0.0, 0.8918918918918919, 0.10810810810810811}, 5 * sizeof(double));
                    } else {
                        memcpy(var47, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 658.6499938964844) {
            if (input[1] <= 613.75) {
                if (input[2] <= 611.75) {
                    if (input[0] <= 603.1499938964844) {
                        memcpy(var47, (double[]){0.0, 0.871313672922252, 0.0, 0.128686327077748, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var47, (double[]){0.0, 0.9322033898305084, 0.0, 0.06779661016949153, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 612.8500061035156) {
                        memcpy(var47, (double[]){0.0, 0.543859649122807, 0.0, 0.45614035087719296, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var47, (double[]){0.0, 0.8846153846153846, 0.0, 0.11538461538461539, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 618.75) {
                    if (input[2] <= 618.6499938964844) {
                        memcpy(var47, (double[]){0.0, 0.9823529411764705, 0.0, 0.01764705882352941, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var47, (double[]){0.0, 0.7777777777777778, 0.0, 0.2222222222222222, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var47, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var47, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var14, var47, 5, var13);
    double var48[5];
    if (input[1] <= 598.1999816894531) {
        if (input[0] <= 552.3500061035156) {
            if (input[0] <= 454.5500030517578) {
                if (input[0] <= 390.34999084472656) {
                    if (input[2] <= 388.65000915527344) {
                        memcpy(var48, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var48, (double[]){0.9, 0.0, 0.0, 0.0, 0.1}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 396.0500030517578) {
                        memcpy(var48, (double[]){0.5901639344262295, 0.0, 0.0, 0.0, 0.4098360655737705}, 5 * sizeof(double));
                    } else {
                        memcpy(var48, (double[]){0.8345381526104417, 0.0, 0.0, 0.0, 0.16546184738955824}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 480.4499969482422) {
                    if (input[1] <= 460.75) {
                        memcpy(var48, (double[]){0.2127659574468085, 0.0, 0.0, 0.0, 0.7872340425531915}, 5 * sizeof(double));
                    } else {
                        memcpy(var48, (double[]){0.464, 0.0, 0.0, 0.0, 0.536}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 492.65000915527344) {
                        memcpy(var48, (double[]){0.12035010940919037, 0.0, 0.0, 0.0, 0.8796498905908097}, 5 * sizeof(double));
                    } else {
                        memcpy(var48, (double[]){0.08187134502923976, 0.0, 0.0, 0.1440058479532164, 0.7741228070175439}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 573.9500122070312) {
                if (input[2] <= 556.5500183105469) {
                    if (input[2] <= 553.75) {
                        memcpy(var48, (double[]){0.07317073170731708, 0.0, 0.0, 0.8414634146341464, 0.0853658536585366}, 5 * sizeof(double));
                    } else {
                        memcpy(var48, (double[]){0.31578947368421056, 0.0, 0.0, 0.44736842105263164, 0.2368421052631579}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 561.25) {
                        memcpy(var48, (double[]){0.033542976939203356, 0.0, 0.0, 0.9475890985324947, 0.018867924528301886}, 5 * sizeof(double));
                    } else {
                        memcpy(var48, (double[]){0.007984031936127744, 0.0, 0.0, 0.9920159680638723, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 586.1000061035156) {
                    if (input[1] <= 577.8000183105469) {
                        memcpy(var48, (double[]){0.04477611940298507, 0.0, 0.0, 0.3880597014925373, 0.5671641791044776}, 5 * sizeof(double));
                    } else {
                        memcpy(var48, (double[]){0.11038961038961038, 0.0, 0.0, 0.5454545454545454, 0.34415584415584416}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 586.75) {
                        memcpy(var48, (double[]){0.0, 0.0, 0.0, 0.9032258064516129, 0.0967741935483871}, 5 * sizeof(double));
                    } else {
                        memcpy(var48, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 658.6499938964844) {
            if (input[2] <= 616.75) {
                if (input[1] <= 601.3500061035156) {
                    if (input[0] <= 599.3500061035156) {
                        memcpy(var48, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var48, (double[]){0.0, 0.8312236286919831, 0.0, 0.16877637130801687, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 611.0499877929688) {
                        memcpy(var48, (double[]){0.0, 0.944359756097561, 0.0, 0.055640243902439025, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var48, (double[]){0.0, 0.7903780068728522, 0.0, 0.20962199312714777, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 617.5499877929688) {
                    if (input[1] <= 617.8499755859375) {
                        memcpy(var48, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var48, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var48, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var48, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var13, var48, 5, var12);
    double var49[5];
    if (input[2] <= 598.5499877929688) {
        if (input[2] <= 551.25) {
            if (input[1] <= 451.0) {
                if (input[0] <= 391.34999084472656) {
                    if (input[1] <= 388.25) {
                        memcpy(var49, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var49, (double[]){0.9666666666666667, 0.0, 0.0, 0.0, 0.03333333333333333}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 395.5) {
                        memcpy(var49, (double[]){0.5510204081632653, 0.0, 0.0, 0.0, 0.4489795918367347}, 5 * sizeof(double));
                    } else {
                        memcpy(var49, (double[]){0.8468468468468469, 0.0, 0.0, 0.0, 0.15315315315315314}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 480.5500030517578) {
                    if (input[2] <= 471.34999084472656) {
                        memcpy(var49, (double[]){0.48687350835322196, 0.0, 0.0, 0.0, 0.513126491646778}, 5 * sizeof(double));
                    } else {
                        memcpy(var49, (double[]){0.35185185185185186, 0.0, 0.0, 0.0, 0.6481481481481481}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.34999084472656) {
                        memcpy(var49, (double[]){0.13034188034188035, 0.0, 0.0, 0.0, 0.8696581196581197}, 5 * sizeof(double));
                    } else {
                        memcpy(var49, (double[]){0.08379888268156424, 0.0, 0.0, 0.125, 0.7912011173184358}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 574.4500122070312) {
                if (input[1] <= 556.9499816894531) {
                    if (input[1] <= 553.0499877929688) {
                        memcpy(var49, (double[]){0.008620689655172414, 0.0, 0.0, 0.9224137931034483, 0.06896551724137931}, 5 * sizeof(double));
                    } else {
                        memcpy(var49, (double[]){0.2677165354330709, 0.0, 0.0, 0.5748031496062992, 0.15748031496062992}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 568.0499877929688) {
                        memcpy(var49, (double[]){0.028716216216216218, 0.0, 0.0, 0.9594594594594594, 0.011824324324324325}, 5 * sizeof(double));
                    } else {
                        memcpy(var49, (double[]){0.0051813471502590676, 0.0, 0.0, 0.9922279792746114, 0.0025906735751295338}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 584.1499938964844) {
                    if (input[0] <= 578.3500061035156) {
                        memcpy(var49, (double[]){0.04081632653061224, 0.0, 0.0, 0.30612244897959184, 0.6530612244897959}, 5 * sizeof(double));
                    } else {
                        memcpy(var49, (double[]){0.12403100775193798, 0.0, 0.0, 0.5968992248062015, 0.27906976744186046}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 586.75) {
                        memcpy(var49, (double[]){0.0, 0.0, 0.0, 0.9069767441860465, 0.09302325581395349}, 5 * sizeof(double));
                    } else {
                        memcpy(var49, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 658.1499938964844) {
            if (input[1] <= 618.1499938964844) {
                if (input[0] <= 599.3500061035156) {
                    memcpy(var49, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[1] <= 610.9500122070312) {
                        memcpy(var49, (double[]){0.0, 0.9260188087774295, 0.0, 0.07398119122257053, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var49, (double[]){0.0, 0.8, 0.0, 0.2, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                memcpy(var49, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
            }
        } else {
            memcpy(var49, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var12, var49, 5, var11);
    double var50[5];
    if (input[1] <= 598.1999816894531) {
        if (input[2] <= 551.25) {
            if (input[2] <= 450.6499938964844) {
                if (input[0] <= 390.34999084472656) {
                    memcpy(var50, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[0] <= 391.8999938964844) {
                        memcpy(var50, (double[]){0.2631578947368421, 0.0, 0.0, 0.0, 0.7368421052631579}, 5 * sizeof(double));
                    } else {
                        memcpy(var50, (double[]){0.8374052232518955, 0.0, 0.0, 0.0, 0.16259477674810446}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 480.25) {
                    if (input[2] <= 462.5500030517578) {
                        memcpy(var50, (double[]){0.36075949367088606, 0.0, 0.0, 0.0, 0.6392405063291139}, 5 * sizeof(double));
                    } else {
                        memcpy(var50, (double[]){0.4796747967479675, 0.0, 0.0, 0.0, 0.5203252032520326}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.4499969482422) {
                        memcpy(var50, (double[]){0.10352941176470588, 0.0, 0.0, 0.0, 0.8964705882352941}, 5 * sizeof(double));
                    } else {
                        memcpy(var50, (double[]){0.08768406961178045, 0.0, 0.0, 0.12449799196787148, 0.7878179384203481}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 575.2000122070312) {
                if (input[2] <= 557.1000061035156) {
                    if (input[1] <= 552.8500061035156) {
                        memcpy(var50, (double[]){0.008620689655172414, 0.0, 0.0, 0.8879310344827587, 0.10344827586206896}, 5 * sizeof(double));
                    } else {
                        memcpy(var50, (double[]){0.30714285714285716, 0.0, 0.0, 0.5285714285714286, 0.16428571428571428}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 557.25) {
                        memcpy(var50, (double[]){0.0, 0.0, 0.0, 0.5, 0.5}, 5 * sizeof(double));
                    } else {
                        memcpy(var50, (double[]){0.02145922746781116, 0.0, 0.0, 0.9678111587982833, 0.01072961373390558}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 577.4499816894531) {
                    if (input[0] <= 576.1999816894531) {
                        memcpy(var50, (double[]){0.0, 0.0, 0.0, 0.5, 0.5}, 5 * sizeof(double));
                    } else {
                        memcpy(var50, (double[]){0.02857142857142857, 0.0, 0.0, 0.08571428571428572, 0.8857142857142857}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 586.6499938964844) {
                        memcpy(var50, (double[]){0.10674157303370786, 0.0, 0.0, 0.6292134831460674, 0.2640449438202247}, 5 * sizeof(double));
                    } else {
                        memcpy(var50, (double[]){0.0, 0.0, 0.0, 0.9928571428571429, 0.007142857142857143}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 657.8500061035156) {
            if (input[0] <= 599.4500122070312) {
                if (input[1] <= 598.5499877929688) {
                    if (input[0] <= 599.1000061035156) {
                        memcpy(var50, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var50, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var50, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                }
            } else {
                if (input[2] <= 613.1499938964844) {
                    if (input[2] <= 612.4500122070312) {
                        memcpy(var50, (double[]){0.0, 0.9192510239906378, 0.0, 0.0807489760093622, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var50, (double[]){0.0, 0.38636363636363635, 0.0, 0.6136363636363636, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 618.75) {
                        memcpy(var50, (double[]){0.0, 0.9668508287292817, 0.0, 0.03314917127071823, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var50, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            memcpy(var50, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var11, var50, 5, var10);
    double var51[5];
    if (input[0] <= 599.3500061035156) {
        if (input[0] <= 552.1000061035156) {
            if (input[0] <= 451.5) {
                if (input[1] <= 389.5500030517578) {
                    if (input[2] <= 388.6999969482422) {
                        memcpy(var51, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var51, (double[]){0.9411764705882353, 0.0, 0.0, 0.0, 0.058823529411764705}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 397.65000915527344) {
                        memcpy(var51, (double[]){0.6060606060606061, 0.0, 0.0, 0.0, 0.3939393939393939}, 5 * sizeof(double));
                    } else {
                        memcpy(var51, (double[]){0.8222029488291414, 0.0, 0.0, 0.0, 0.17779705117085862}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 479.4499969482422) {
                    if (input[2] <= 457.1999969482422) {
                        memcpy(var51, (double[]){0.23232323232323232, 0.0, 0.0, 0.0, 0.7676767676767676}, 5 * sizeof(double));
                    } else {
                        memcpy(var51, (double[]){0.40892193308550184, 0.0, 0.0, 0.0, 0.5910780669144982}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 492.65000915527344) {
                        memcpy(var51, (double[]){0.12448132780082988, 0.0, 0.0, 0.002074688796680498, 0.8734439834024896}, 5 * sizeof(double));
                    } else {
                        memcpy(var51, (double[]){0.09046961325966851, 0.0, 0.0, 0.14502762430939226, 0.7645027624309392}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 573.9500122070312) {
                if (input[1] <= 556.8999938964844) {
                    if (input[1] <= 553.0499877929688) {
                        memcpy(var51, (double[]){0.008264462809917356, 0.0, 0.0, 0.8760330578512396, 0.11570247933884298}, 5 * sizeof(double));
                    } else {
                        memcpy(var51, (double[]){0.3178294573643411, 0.0, 0.0, 0.5038759689922481, 0.17829457364341086}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 558.4500122070312) {
                        memcpy(var51, (double[]){0.01910828025477707, 0.0, 0.0, 0.9235668789808917, 0.05732484076433121}, 5 * sizeof(double));
                    } else {
                        memcpy(var51, (double[]){0.011349306431273645, 0.0, 0.0, 0.987389659520807, 0.0012610340479192938}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 584.9500122070312) {
                    if (input[2] <= 577.75) {
                        memcpy(var51, (double[]){0.015151515151515152, 0.0, 0.0, 0.36363636363636365, 0.6212121212121212}, 5 * sizeof(double));
                    } else {
                        memcpy(var51, (double[]){0.13986013986013987, 0.0, 0.0, 0.5804195804195804, 0.27972027972027974}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 587.1000061035156) {
                        memcpy(var51, (double[]){0.0, 0.0, 0.0, 0.8076923076923077, 0.19230769230769232}, 5 * sizeof(double));
                    } else {
                        memcpy(var51, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 658.1499938964844) {
            if (input[1] <= 617.25) {
                if (input[2] <= 611.0499877929688) {
                    if (input[2] <= 605.8500061035156) {
                        memcpy(var51, (double[]){0.0, 0.9127789046653144, 0.0, 0.0872210953346856, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var51, (double[]){0.0, 0.9575163398692811, 0.0, 0.042483660130718956, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 612.6499938964844) {
                        memcpy(var51, (double[]){0.0, 0.6847826086956522, 0.0, 0.31521739130434784, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var51, (double[]){0.0, 0.9146341463414634, 0.0, 0.08536585365853659, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 618.75) {
                    if (input[2] <= 617.5499877929688) {
                        memcpy(var51, (double[]){0.0, 0.9, 0.0, 0.1, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var51, (double[]){0.0, 0.9811320754716981, 0.0, 0.018867924528301886, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var51, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var51, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var10, var51, 5, var9);
    double var52[5];
    if (input[1] <= 598.1999816894531) {
        if (input[2] <= 551.3500061035156) {
            if (input[2] <= 450.84999084472656) {
                if (input[2] <= 388.65000915527344) {
                    memcpy(var52, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[1] <= 396.15000915527344) {
                        memcpy(var52, (double[]){0.5735294117647058, 0.0, 0.0, 0.0, 0.4264705882352941}, 5 * sizeof(double));
                    } else {
                        memcpy(var52, (double[]){0.819614711033275, 0.0, 0.0, 0.0, 0.18038528896672504}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 480.5500030517578) {
                    if (input[1] <= 462.25) {
                        memcpy(var52, (double[]){0.3081395348837209, 0.0, 0.0, 0.0, 0.6918604651162791}, 5 * sizeof(double));
                    } else {
                        memcpy(var52, (double[]){0.44467640918580376, 0.0, 0.0, 0.0, 0.5553235908141962}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 493.4499969482422) {
                        memcpy(var52, (double[]){0.11397849462365592, 0.0, 0.0, 0.0, 0.886021505376344}, 5 * sizeof(double));
                    } else {
                        memcpy(var52, (double[]){0.08211551844119694, 0.0, 0.0, 0.13639526791927628, 0.7814892136395268}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 573.9500122070312) {
                if (input[1] <= 557.25) {
                    if (input[2] <= 553.75) {
                        memcpy(var52, (double[]){0.0449438202247191, 0.0, 0.0, 0.8202247191011236, 0.1348314606741573}, 5 * sizeof(double));
                    } else {
                        memcpy(var52, (double[]){0.24719101123595505, 0.0, 0.0, 0.5056179775280899, 0.24719101123595505}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 558.4500122070312) {
                        memcpy(var52, (double[]){0.03787878787878789, 0.0, 0.0, 0.9090909090909092, 0.05303030303030304}, 5 * sizeof(double));
                    } else {
                        memcpy(var52, (double[]){0.017834394904458598, 0.0, 0.0, 0.9796178343949045, 0.0025477707006369425}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 585.1499938964844) {
                    if (input[2] <= 580.25) {
                        memcpy(var52, (double[]){0.06629834254143646, 0.0, 0.0, 0.569060773480663, 0.36464088397790057}, 5 * sizeof(double));
                    } else {
                        memcpy(var52, (double[]){0.425, 0.0, 0.0, 0.425, 0.15}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 586.6499938964844) {
                        memcpy(var52, (double[]){0.0, 0.0, 0.0, 0.8571428571428571, 0.14285714285714285}, 5 * sizeof(double));
                    } else {
                        memcpy(var52, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 658.1499938964844) {
            if (input[1] <= 612.8500061035156) {
                if (input[1] <= 612.6499938964844) {
                    if (input[0] <= 599.4500122070312) {
                        memcpy(var52, (double[]){0.0, 0.05263157894736842, 0.0, 0.9473684210526315, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var52, (double[]){0.0, 0.9220623501199041, 0.0, 0.07793764988009592, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 612.9500122070312) {
                        memcpy(var52, (double[]){0.0, 0.16666666666666666, 0.0, 0.8333333333333334, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var52, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 615.5) {
                    if (input[1] <= 614.5499877929688) {
                        memcpy(var52, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var52, (double[]){0.0, 0.8695652173913043, 0.0, 0.13043478260869565, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 618.75) {
                        memcpy(var52, (double[]){0.0, 0.9916666666666667, 0.0, 0.008333333333333333, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var52, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            memcpy(var52, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var9, var52, 5, var8);
    double var53[5];
    if (input[1] <= 598.1999816894531) {
        if (input[2] <= 550.9499816894531) {
            if (input[2] <= 450.6499938964844) {
                if (input[0] <= 390.34999084472656) {
                    if (input[2] <= 388.65000915527344) {
                        memcpy(var53, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var53, (double[]){0.9090909090909091, 0.0, 0.0, 0.0, 0.09090909090909091}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 397.65000915527344) {
                        memcpy(var53, (double[]){0.5526315789473685, 0.0, 0.0, 0.0, 0.4473684210526316}, 5 * sizeof(double));
                    } else {
                        memcpy(var53, (double[]){0.8309859154929577, 0.0, 0.0, 0.0, 0.16901408450704225}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 480.4499969482422) {
                    if (input[2] <= 464.25) {
                        memcpy(var53, (double[]){0.34684684684684686, 0.0, 0.0, 0.0, 0.6531531531531531}, 5 * sizeof(double));
                    } else {
                        memcpy(var53, (double[]){0.48444444444444446, 0.0, 0.0, 0.0, 0.5155555555555555}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.34999084472656) {
                        memcpy(var53, (double[]){0.10927835051546392, 0.0, 0.0, 0.0, 0.8907216494845361}, 5 * sizeof(double));
                    } else {
                        memcpy(var53, (double[]){0.09993011879804332, 0.0, 0.0, 0.1264849755415793, 0.7735849056603774}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 574.0499877929688) {
                if (input[1] <= 556.9499816894531) {
                    if (input[0] <= 554.8500061035156) {
                        memcpy(var53, (double[]){0.07222222222222222, 0.0, 0.0, 0.8333333333333334, 0.09444444444444444}, 5 * sizeof(double));
                    } else {
                        memcpy(var53, (double[]){0.3698630136986301, 0.0, 0.0, 0.410958904109589, 0.2191780821917808}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 568.0499877929688) {
                        memcpy(var53, (double[]){0.029315960912052116, 0.0, 0.0, 0.9641693811074918, 0.006514657980456026}, 5 * sizeof(double));
                    } else {
                        memcpy(var53, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 586.8500061035156) {
                    if (input[2] <= 577.75) {
                        memcpy(var53, (double[]){0.037037037037037035, 0.0, 0.0, 0.4074074074074074, 0.5555555555555556}, 5 * sizeof(double));
                    } else {
                        memcpy(var53, (double[]){0.047619047619047616, 0.0, 0.0, 0.6785714285714286, 0.27380952380952384}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 587.1000061035156) {
                        memcpy(var53, (double[]){0.0, 0.0, 0.0, 0.8571428571428571, 0.14285714285714285}, 5 * sizeof(double));
                    } else {
                        memcpy(var53, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 658.6499938964844) {
            if (input[0] <= 599.4500122070312) {
                if (input[1] <= 598.6499938964844) {
                    if (input[2] <= 598.5499877929688) {
                        memcpy(var53, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var53, (double[]){0.0, 0.5, 0.0, 0.5, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var53, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                }
            } else {
                if (input[2] <= 615.8500061035156) {
                    if (input[1] <= 610.1499938964844) {
                        memcpy(var53, (double[]){0.0, 0.9391249207355739, 0.0, 0.060875079264426125, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var53, (double[]){0.0, 0.8023715415019763, 0.0, 0.1976284584980237, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 618.75) {
                        memcpy(var53, (double[]){0.0, 0.9672131147540983, 0.0, 0.03278688524590164, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var53, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            memcpy(var53, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var8, var53, 5, var7);
    double var54[5];
    if (input[1] <= 598.1999816894531) {
        if (input[2] <= 550.9499816894531) {
            if (input[0] <= 452.6999969482422) {
                if (input[0] <= 389.6999969482422) {
                    memcpy(var54, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[0] <= 397.75) {
                        memcpy(var54, (double[]){0.5324675324675324, 0.0, 0.0, 0.0, 0.4675324675324675}, 5 * sizeof(double));
                    } else {
                        memcpy(var54, (double[]){0.8279192273924495, 0.0, 0.0, 0.0, 0.17208077260755048}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 479.84999084472656) {
                    if (input[2] <= 471.3999938964844) {
                        memcpy(var54, (double[]){0.4839506172839506, 0.0, 0.0, 0.0, 0.5160493827160494}, 5 * sizeof(double));
                    } else {
                        memcpy(var54, (double[]){0.38207547169811323, 0.0, 0.0, 0.0, 0.6179245283018868}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 493.3500061035156) {
                        memcpy(var54, (double[]){0.11530815109343936, 0.0, 0.0, 0.0, 0.8846918489065606}, 5 * sizeof(double));
                    } else {
                        memcpy(var54, (double[]){0.08635097493036212, 0.0, 0.0, 0.13997214484679665, 0.7736768802228412}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 557.1000061035156) {
                if (input[2] <= 553.0499877929688) {
                    if (input[2] <= 552.25) {
                        memcpy(var54, (double[]){0.0, 0.0, 0.0, 0.96, 0.04}, 5 * sizeof(double));
                    } else {
                        memcpy(var54, (double[]){0.03921568627450981, 0.0, 0.0, 0.7647058823529412, 0.19607843137254904}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 555.8999938964844) {
                        memcpy(var54, (double[]){0.32000000000000006, 0.0, 0.0, 0.5920000000000001, 0.08800000000000001}, 5 * sizeof(double));
                    } else {
                        memcpy(var54, (double[]){0.4117647058823529, 0.0, 0.0, 0.23529411764705882, 0.35294117647058826}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 574.1000061035156) {
                    if (input[0] <= 566.2999877929688) {
                        memcpy(var54, (double[]){0.0345489443378119, 0.0, 0.0, 0.9404990403071017, 0.02495201535508637}, 5 * sizeof(double));
                    } else {
                        memcpy(var54, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 585.1499938964844) {
                        memcpy(var54, (double[]){0.10240963855421686, 0.0, 0.0, 0.4939759036144578, 0.4036144578313253}, 5 * sizeof(double));
                    } else {
                        memcpy(var54, (double[]){0.0, 0.0, 0.0, 0.994535519125683, 0.00546448087431694}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 658.6499938964844) {
            if (input[0] <= 599.4500122070312) {
                if (input[1] <= 598.6499938964844) {
                    if (input[0] <= 599.1500244140625) {
                        memcpy(var54, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var54, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var54, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                }
            } else {
                if (input[2] <= 615.4500122070312) {
                    if (input[0] <= 612.25) {
                        memcpy(var54, (double[]){0.0, 0.9333333333333333, 0.0, 0.06666666666666667, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var54, (double[]){0.0, 0.773972602739726, 0.0, 0.22602739726027396, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 617.1499938964844) {
                        memcpy(var54, (double[]){0.0, 0.9803921568627451, 0.0, 0.0196078431372549, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var54, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            memcpy(var54, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var7, var54, 5, var6);
    double var55[5];
    if (input[0] <= 599.4500122070312) {
        if (input[1] <= 550.8500061035156) {
            if (input[2] <= 450.5) {
                if (input[0] <= 390.34999084472656) {
                    if (input[0] <= 389.75) {
                        memcpy(var55, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var55, (double[]){0.9166666666666666, 0.0, 0.0, 0.0, 0.08333333333333333}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 397.25) {
                        memcpy(var55, (double[]){0.573170731707317, 0.0, 0.0, 0.0, 0.4268292682926829}, 5 * sizeof(double));
                    } else {
                        memcpy(var55, (double[]){0.8336298932384342, 0.0, 0.0, 0.0, 0.16637010676156583}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 481.0) {
                    if (input[0] <= 457.0500030517578) {
                        memcpy(var55, (double[]){0.21666666666666667, 0.0, 0.0, 0.0, 0.7833333333333333}, 5 * sizeof(double));
                    } else {
                        memcpy(var55, (double[]){0.45685279187817257, 0.0, 0.0, 0.0, 0.5431472081218274}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.3000030517578) {
                        memcpy(var55, (double[]){0.11041666666666666, 0.0, 0.0, 0.0, 0.8895833333333333}, 5 * sizeof(double));
                    } else {
                        memcpy(var55, (double[]){0.0875, 0.0, 0.0, 0.1375, 0.775}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 573.9500122070312) {
                if (input[2] <= 557.1000061035156) {
                    if (input[2] <= 553.0499877929688) {
                        memcpy(var55, (double[]){0.02654867256637168, 0.0, 0.0, 0.8849557522123894, 0.08849557522123894}, 5 * sizeof(double));
                    } else {
                        memcpy(var55, (double[]){0.2553191489361702, 0.0, 0.0, 0.5886524822695035, 0.15602836879432624}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 557.25) {
                        memcpy(var55, (double[]){0.0, 0.0, 0.0, 0.6666666666666666, 0.3333333333333333}, 5 * sizeof(double));
                    } else {
                        memcpy(var55, (double[]){0.016163793103448277, 0.0, 0.0, 0.9773706896551724, 0.00646551724137931}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 585.1999816894531) {
                    if (input[0] <= 575.3500061035156) {
                        memcpy(var55, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var55, (double[]){0.116751269035533, 0.0, 0.0, 0.4467005076142132, 0.4365482233502538}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 586.3500061035156) {
                        memcpy(var55, (double[]){0.0, 0.0, 0.0, 0.8333333333333334, 0.16666666666666666}, 5 * sizeof(double));
                    } else {
                        memcpy(var55, (double[]){0.0, 0.005681818181818182, 0.0, 0.9943181818181818, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 657.8500061035156) {
            if (input[2] <= 617.25) {
                if (input[2] <= 611.4500122070312) {
                    if (input[1] <= 600.4500122070312) {
                        memcpy(var55, (double[]){0.0, 0.8552631578947368, 0.0, 0.14473684210526316, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var55, (double[]){0.0, 0.9416498993963782, 0.0, 0.05835010060362173, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 613.1499938964844) {
                        memcpy(var55, (double[]){0.0, 0.6571428571428571, 0.0, 0.34285714285714286, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var55, (double[]){0.0, 0.9076923076923077, 0.0, 0.09230769230769231, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 618.75) {
                    if (input[0] <= 618.8500061035156) {
                        memcpy(var55, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var55, (double[]){0.0, 0.9166666666666666, 0.0, 0.08333333333333333, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var55, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var55, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var6, var55, 5, var5);
    double var56[5];
    if (input[2] <= 598.5499877929688) {
        if (input[1] <= 550.9499816894531) {
            if (input[2] <= 450.5500030517578) {
                if (input[0] <= 389.75) {
                    memcpy(var56, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[0] <= 430.5500030517578) {
                        memcpy(var56, (double[]){0.8004459308807135, 0.0, 0.0, 0.0, 0.1995540691192865}, 5 * sizeof(double));
                    } else {
                        memcpy(var56, (double[]){0.9010238907849829, 0.0, 0.0, 0.0, 0.09897610921501707}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 481.75) {
                    if (input[2] <= 471.8999938964844) {
                        memcpy(var56, (double[]){0.4617067833698031, 0.0, 0.0, 0.0, 0.5382932166301969}, 5 * sizeof(double));
                    } else {
                        memcpy(var56, (double[]){0.35023041474654376, 0.0, 0.0, 0.0, 0.6497695852534562}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.75) {
                        memcpy(var56, (double[]){0.11956521739130435, 0.0, 0.0, 0.0, 0.8804347826086957}, 5 * sizeof(double));
                    } else {
                        memcpy(var56, (double[]){0.10085227272727272, 0.0, 0.0, 0.14772727272727273, 0.7514204545454546}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 573.9500122070312) {
                if (input[1] <= 556.9499816894531) {
                    if (input[0] <= 555.1499938964844) {
                        memcpy(var56, (double[]){0.05291005291005291, 0.0, 0.0, 0.8359788359788359, 0.1111111111111111}, 5 * sizeof(double));
                    } else {
                        memcpy(var56, (double[]){0.36507936507936506, 0.0, 0.0, 0.4603174603174603, 0.1746031746031746}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 558.25) {
                        memcpy(var56, (double[]){0.0, 0.0, 0.0, 0.9477611940298507, 0.05223880597014925}, 5 * sizeof(double));
                    } else {
                        memcpy(var56, (double[]){0.020706455542021926, 0.0, 0.0, 0.9780755176613886, 0.001218026796589525}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 586.75) {
                    if (input[2] <= 577.75) {
                        memcpy(var56, (double[]){0.019230769230769232, 0.0, 0.0, 0.36538461538461536, 0.6153846153846154}, 5 * sizeof(double));
                    } else {
                        memcpy(var56, (double[]){0.10526315789473684, 0.0, 0.0, 0.5906432748538012, 0.30409356725146197}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var56, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                }
            }
        }
    } else {
        if (input[0] <= 658.6499938964844) {
            if (input[1] <= 602.1499938964844) {
                if (input[2] <= 602.4500122070312) {
                    if (input[1] <= 598.1999816894531) {
                        memcpy(var56, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var56, (double[]){0.0, 0.8429752066115702, 0.0, 0.15702479338842976, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 602.5499877929688) {
                        memcpy(var56, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var56, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 617.25) {
                    if (input[1] <= 611.6499938964844) {
                        memcpy(var56, (double[]){0.0, 0.9519586104951958, 0.0, 0.04804138950480414, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var56, (double[]){0.0, 0.8516746411483254, 0.0, 0.14832535885167464, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var56, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var56, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var5, var56, 5, var4);
    double var57[5];
    if (input[1] <= 598.1999816894531) {
        if (input[1] <= 451.15000915527344) {
            if (input[0] <= 389.6999969482422) {
                memcpy(var57, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
            } else {
                if (input[1] <= 397.4499969482422) {
                    if (input[1] <= 394.84999084472656) {
                        memcpy(var57, (double[]){0.7142857142857143, 0.0, 0.0, 0.0, 0.2857142857142857}, 5 * sizeof(double));
                    } else {
                        memcpy(var57, (double[]){0.40625, 0.0, 0.0, 0.0, 0.59375}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 414.0) {
                        memcpy(var57, (double[]){0.9118457300275482, 0.0, 0.0, 0.0, 0.0881542699724518}, 5 * sizeof(double));
                    } else {
                        memcpy(var57, (double[]){0.8302872062663186, 0.0, 0.0, 0.0, 0.16971279373368145}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 550.8500061035156) {
                if (input[2] <= 477.75) {
                    if (input[1] <= 464.5500030517578) {
                        memcpy(var57, (double[]){0.26519337016574585, 0.0, 0.0, 0.0, 0.7348066298342542}, 5 * sizeof(double));
                    } else {
                        memcpy(var57, (double[]){0.5052083333333334, 0.0, 0.0, 0.0, 0.4947916666666667}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.5500030517578) {
                        memcpy(var57, (double[]){0.13003663003663005, 0.0, 0.0, 0.0, 0.86996336996337}, 5 * sizeof(double));
                    } else {
                        memcpy(var57, (double[]){0.07827926657263752, 0.0, 0.0, 0.1466854724964739, 0.7750352609308886}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 574.1000061035156) {
                    if (input[2] <= 557.0500183105469) {
                        memcpy(var57, (double[]){0.16733067729083664, 0.0, 0.0, 0.7330677290836654, 0.099601593625498}, 5 * sizeof(double));
                    } else {
                        memcpy(var57, (double[]){0.021052631578947368, 0.0, 0.0, 0.9705263157894737, 0.008421052631578947}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 584.25) {
                        memcpy(var57, (double[]){0.11165048543689321, 0.0, 0.0, 0.5194174757281553, 0.36893203883495146}, 5 * sizeof(double));
                    } else {
                        memcpy(var57, (double[]){0.0, 0.0, 0.0, 0.9766081871345029, 0.023391812865497075}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 658.1499938964844) {
            if (input[0] <= 599.3500061035156) {
                memcpy(var57, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
            } else {
                if (input[2] <= 617.5499877929688) {
                    if (input[1] <= 610.75) {
                        memcpy(var57, (double[]){0.0, 0.9203484754200373, 0.0, 0.07965152457996266, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var57, (double[]){0.0, 0.8529411764705882, 0.0, 0.14705882352941177, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 618.75) {
                        memcpy(var57, (double[]){0.0, 0.9836065573770492, 0.0, 0.01639344262295082, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var57, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            memcpy(var57, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var4, var57, 5, var3);
    double var58[5];
    if (input[0] <= 599.3500061035156) {
        if (input[2] <= 550.9499816894531) {
            if (input[2] <= 450.84999084472656) {
                if (input[0] <= 389.75) {
                    memcpy(var58, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                } else {
                    if (input[2] <= 429.84999084472656) {
                        memcpy(var58, (double[]){0.8060200668896321, 0.0, 0.0, 0.0, 0.1939799331103679}, 5 * sizeof(double));
                    } else {
                        memcpy(var58, (double[]){0.9006211180124224, 0.0, 0.0, 0.0, 0.09937888198757763}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 480.25) {
                    if (input[1] <= 471.6499938964844) {
                        memcpy(var58, (double[]){0.475, 0.0, 0.0, 0.0, 0.525}, 5 * sizeof(double));
                    } else {
                        memcpy(var58, (double[]){0.3557312252964427, 0.0, 0.0, 0.0, 0.6442687747035574}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 492.34999084472656) {
                        memcpy(var58, (double[]){0.10647181628392484, 0.0, 0.0, 0.0, 0.8935281837160751}, 5 * sizeof(double));
                    } else {
                        memcpy(var58, (double[]){0.08947006194081211, 0.0, 0.0, 0.13145216792842396, 0.779077770130764}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[2] <= 573.9500122070312) {
                if (input[2] <= 557.0500183105469) {
                    if (input[1] <= 553.75) {
                        memcpy(var58, (double[]){0.06547619047619048, 0.0, 0.0, 0.7857142857142857, 0.1488095238095238}, 5 * sizeof(double));
                    } else {
                        memcpy(var58, (double[]){0.34210526315789475, 0.0, 0.0, 0.4605263157894737, 0.19736842105263158}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 557.75) {
                        memcpy(var58, (double[]){0.078125, 0.0, 0.0, 0.921875, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var58, (double[]){0.014192139737991267, 0.0, 0.0, 0.9847161572052402, 0.001091703056768559}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 585.75) {
                    if (input[0] <= 578.3500061035156) {
                        memcpy(var58, (double[]){0.06896551724137931, 0.0, 0.0, 0.3448275862068966, 0.5862068965517241}, 5 * sizeof(double));
                    } else {
                        memcpy(var58, (double[]){0.17164179104477612, 0.0, 0.0, 0.5522388059701493, 0.27611940298507465}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 586.3500061035156) {
                        memcpy(var58, (double[]){0.0, 0.0, 0.0, 0.8947368421052632, 0.10526315789473684}, 5 * sizeof(double));
                    } else {
                        memcpy(var58, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[2] <= 657.75) {
            if (input[2] <= 616.75) {
                if (input[1] <= 611.6499938964844) {
                    if (input[0] <= 603.4500122070312) {
                        memcpy(var58, (double[]){0.0, 0.8829268292682927, 0.0, 0.11707317073170732, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var58, (double[]){0.0, 0.9459684123025769, 0.0, 0.05403158769742311, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 613.75) {
                        memcpy(var58, (double[]){0.0, 0.49230769230769234, 0.0, 0.5076923076923077, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var58, (double[]){0.0, 0.9134615384615384, 0.0, 0.08653846153846154, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 618.75) {
                    if (input[0] <= 618.8500061035156) {
                        memcpy(var58, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var58, (double[]){0.0, 0.8823529411764706, 0.0, 0.11764705882352941, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var58, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var58, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var3, var58, 5, var2);
    double var59[5];
    if (input[1] <= 598.1999816894531) {
        if (input[1] <= 451.15000915527344) {
            if (input[1] <= 388.25) {
                memcpy(var59, (double[]){1.0, 0.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
            } else {
                if (input[1] <= 394.9499969482422) {
                    if (input[2] <= 390.1999969482422) {
                        memcpy(var59, (double[]){0.8846153846153846, 0.0, 0.0, 0.0, 0.11538461538461539}, 5 * sizeof(double));
                    } else {
                        memcpy(var59, (double[]){0.5576923076923077, 0.0, 0.0, 0.0, 0.4423076923076923}, 5 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 412.0500030517578) {
                        memcpy(var59, (double[]){0.9098143236074271, 0.0, 0.0, 0.0, 0.09018567639257294}, 5 * sizeof(double));
                    } else {
                        memcpy(var59, (double[]){0.8138424821002387, 0.0, 0.0, 0.0, 0.18615751789976134}, 5 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[0] <= 552.3000183105469) {
                if (input[1] <= 480.5500030517578) {
                    if (input[1] <= 455.75) {
                        memcpy(var59, (double[]){0.2, 0.0, 0.0, 0.0, 0.8}, 5 * sizeof(double));
                    } else {
                        memcpy(var59, (double[]){0.4542190305206463, 0.0, 0.0, 0.0, 0.5457809694793537}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 493.5500030517578) {
                        memcpy(var59, (double[]){0.10467706013363029, 0.0, 0.0, 0.0, 0.8953229398663697}, 5 * sizeof(double));
                    } else {
                        memcpy(var59, (double[]){0.09349030470914127, 0.0, 0.0, 0.13019390581717452, 0.7763157894736842}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 575.2000122070312) {
                    if (input[2] <= 557.1500244140625) {
                        memcpy(var59, (double[]){0.1504424778761062, 0.0, 0.0, 0.7168141592920354, 0.13274336283185842}, 5 * sizeof(double));
                    } else {
                        memcpy(var59, (double[]){0.015337423312883436, 0.0, 0.0, 0.9734151329243353, 0.011247443762781187}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 584.0499877929688) {
                        memcpy(var59, (double[]){0.12269938650306748, 0.0, 0.0, 0.4723926380368098, 0.4049079754601227}, 5 * sizeof(double));
                    } else {
                        memcpy(var59, (double[]){0.0, 0.0, 0.0, 0.9810126582278481, 0.0189873417721519}, 5 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[1] <= 657.4500122070312) {
            if (input[1] <= 615.25) {
                if (input[0] <= 599.4500122070312) {
                    if (input[1] <= 598.6999816894531) {
                        memcpy(var59, (double[]){0.0, 0.2857142857142857, 0.0, 0.7142857142857143, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var59, (double[]){0.0, 0.0, 0.0, 1.0, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 612.4500122070312) {
                        memcpy(var59, (double[]){0.0, 0.930841121495327, 0.0, 0.0691588785046729, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var59, (double[]){0.0, 0.6240601503759399, 0.0, 0.37593984962406013, 0.0}, 5 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 617.25) {
                    if (input[0] <= 617.25) {
                        memcpy(var59, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                    } else {
                        memcpy(var59, (double[]){0.0, 0.9130434782608695, 0.0, 0.08695652173913043, 0.0}, 5 * sizeof(double));
                    }
                } else {
                    memcpy(var59, (double[]){0.0, 1.0, 0.0, 0.0, 0.0}, 5 * sizeof(double));
                }
            }
        } else {
            memcpy(var59, (double[]){0.0, 0.0, 1.0, 0.0, 0.0}, 5 * sizeof(double));
        }
    }
    add_vectors(var2, var59, 5, var1);
    mul_vector_number(var1, 0.03333333333333333, 5, var0);
    memcpy(output, var0, 5 * sizeof(double));
}


// Wrapper function to match your ESP32 Arduino code
int rf_model_predict(int16_t* input_features, int length) {
    // Convert int16_t array from Arduino to double array for the model
    double model_input[3];
    model_input[0] = (double)input_features[0];
    model_input[1] = (double)input_features[1];
    model_input[2] = (double)input_features[2];

    // Array to hold the probability scores for each class
    double scores[5];

    // Call the m2cgen generated function
    score(model_input, scores);

    // Find the class with the highest probability
    int best_class = 0;
    double max_score = scores[0];

    for(int i = 1; i < 5; i++) {
        if(scores[i] > max_score) {
            max_score = scores[i];
            best_class = i;
        }
    }

    return best_class;
}

#endif
