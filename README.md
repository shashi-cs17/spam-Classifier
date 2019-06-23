# spam-Classifier
Ham amd Spam mail classification


from version ver-0.0 , 
Datas after training (Hyperparameters => (regularization param)lambda = 0; (#hidden_layer_units)SZ_H = 5; )...

![alt text](https://github.com/shashi-cs17/spam-Classifier/blob/ver-0.0/dataAnalysis_ver-0.0.png)


training data-set Analysis ---->

                                    ground truth (SPAM:HAM = 900:2100)
                             
                                 SPAM             HAM
                                            |
                       SPAM       867       |      62    
                                            |
        predicted              -------------|-------------
                                            |
                        HAM        33       |    2038
                                            |
                                            
cross validation data-set Analysis ---->

                                    ground truth (SPAM:HAM = 300:700)
                             
                                 SPAM             HAM
                                            |
                       SPAM       269       |      52    
                                            |
        predicted              -------------|-------------
                                            |
                        HAM        31       |     648
                                            |
                                            
                                            
test data-set Analysis ---->

                                    ground truth (SPAM:HAM = 300:700)
                             
                                 SPAM             HAM
                                            |
                       SPAM       288       |      61    
                                            |
        predicted              -------------|-------------
                                            |
                        HAM        12       |     639 
                                            |      
                                            
                                            
                                  test_set accuracy = 92.7%
                                            
                                            
                                            
                                            
                                            
                                            
                                            
