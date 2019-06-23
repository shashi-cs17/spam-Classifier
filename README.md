# spam-Classifier
Ham amd Spam mail classification


from version ver-0.0 , 
Datas after training (Hyperparameters => (regularization param)lambda = 0; (#hidden_layer_units)SZ_H = 5; )...

![alt text](https://github.com/shashi-cs17/spam-Classifier/blob/ver-0.0/dataAnalysis_ver-0.0.png)


training data-set Analysis ---->

                                    ground truth (SPAM:HAM = 900:2100)
                             
                                 SPAM             HAM
                                            |
                       SPAM       868       |      48    
                                            |
        predicted              -------------|-------------
                                            |
                        HAM        32       |    2052
                                            |
                                            
cross validation data-set Analysis ---->

                                    ground truth (SPAM:HAM = 300:700)
                             
                                 SPAM             HAM
                                            |
                       SPAM       268       |      27    
                                            |
        predicted              -------------|-------------
                                            |
                        HAM        32       |     673
                                            |
                                            
                                            
test data-set Analysis ---->

                                    ground truth (SPAM:HAM = 300:700)
                             
                                 SPAM             HAM
                                            |
                       SPAM       281       |      48    
                                            |
        predicted              -------------|-------------
                                            |
                        HAM        19       |     652 
                                            |      
                                            
                                            
                                  test_set accuracy = 93.3%
                                            
                                            
                                            
                                            
                                            
                                            
                                            
