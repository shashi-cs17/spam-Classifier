# spam-Classifier
Ham amd Spam mail classification

More About Model ----> Model.txt

from version ver-0.0 , 
Datas after training (Hyperparameters => (regularization param)lambda = 0; (#hidden_layer_units)SZ_H = 5; )...

![dataAnalysis_ver-0.0.png](https://github.com/shashi-cs17/spam-Classifier/blob/ver-0.0/dataAnalysis_ver-0.0.png)


training data-set Analysis ---->

                                    ground truth (SPAM:HAM = 900:2100)
                             
                                 SPAM             HAM
                                            |
                       SPAM       868       |      48    
                                            |
        predicted              -------------|-------------              training_set accuracy = 97.33%
                                            |
                        HAM        32       |    2052
                                            |
                                            
cross validation data-set Analysis ---->

                                    ground truth (SPAM:HAM = 300:700)
                             
                                 SPAM             HAM
                                            |
                       SPAM       268       |      27    
                                            |
        predicted              -------------|-------------              cv_set accuracy =  94.1%
                                            |                           precision       =  0.908
                        HAM        32       |     673                   recall          =  0.893
                                            |
                                            
                                            

Relevant Data ::                       
                                        
                    test_set accuracy (SPAM:HAM = 300:700) = 93.3%
                                            
end
