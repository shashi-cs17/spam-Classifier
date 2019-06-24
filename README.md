# spam-Classifier
Ham amd Spam mail classification

More About Model ----> Model.txt

from version ver-0.0 , 
Datas after training (Hyperparameters => (regularization param)lambda = 0.03; (#hidden_layer_units)SZ_H = 16; )...

![hamAnalysis_ver-0.0.png](https://github.com/shashi-cs17/spam-Classifier/blob/ver-0.1/hamAnalysis_ver-0.1.png)
![spamAnalysis_ver-0.0.png](https://github.com/shashi-cs17/spam-Classifier/blob/ver-0.1/spamAnalysis_ver-0.1.png)
![learningCurve_ver-0.0.png](https://github.com/shashi-cs17/spam-Classifier/blob/ver-0.1/learningCurve_ver-0.1.png)


Relevant Data ::                       
      
                               training_set_accuray (SPAM:HAM = 900:2100)= 99.46%
                               cross_validation_set accuracy (SPAM:HAM = 300:700) = 97%
              cv_set precision(P) = 0.95   cv_set recall(R) = 0.94  cv_set comparable value (2*P*R/(P+R)) = 0.94      
                               test_set accuracy (SPAM:HAM = 300:700) = 95.3%
                                            
end
