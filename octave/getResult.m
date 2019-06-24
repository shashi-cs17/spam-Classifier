function [train_mat cv_mat test_mat train_error cv_error test_error Theta1 Theta2] = getResult( Xo, ...
                                                                                                yo, ...
                                                                                                Xn, ...
                                                                                                yn, ...
                                                                                                lambda, ...
                                                                                                SZ_H, iter)
  
  train_mat = zeros(2,2);
  cv_mat = train_mat;
  test_mat = cv_mat;
  
  %
  
  X_train = Xo(1:2100,:);
  y_train = yo(1:2100,:);
  
  X_cv = Xo(2101:2800,:);
  y_cv = yo(2101:2800,:);
  
  X_test = Xo(2801:3500,:);
  y_test = yo(2801:3500,:);
  
  %
  %
  
  
  X_train = [X_train;Xn(1:900,:)];
  y_train = [y_train;yn(1:900,:)];
  
  X_cv = [X_cv;Xn(901:1200,:)];
  y_cv = [y_cv;yn(901:1200,:)];
  
  X_test = [X_test;Xn(1201:1500,:)];
  y_test = [y_test;yn(1201:1500,:)];
  
  
  theta = trainClassifier(X_train, y_train, lambda, SZ_H, iter);
  
  SZ_M = size(X_cv,2);
  
  Theta1 = reshape(theta(1:SZ_H*(SZ_M+1)),SZ_H,SZ_M+1);
  Theta2 = reshape(theta(1+SZ_H*(SZ_M+1):end),2,SZ_H+1);
  
  X_train = [ones(3000,1) X_train];
  X_cv = [ones(1000,1) X_cv];
  X_test = [ones(1000,1) X_test];
  
  Ha = sigmoid(Theta1*X_train');
  pred_y = sigmoid(Theta2*[ones(1,3000);Ha]);
  
  plot(pred_y(1,1:2100),pred_y(2,1:2100),'bo');
  hold on;
  plot(pred_y(1,2101:3000),pred_y(2,2101:3000),'rx');
  xlabel('probability of being Ham');
  ylabel('probability of being Spam');
  title('Predicted probabilitities of training data (red cross = spam, blue circle = ham)');
  hold off;
  
  %printf("training data ====\n");
  [train_mat train_error] = computeTable(pred_y, 2100);
  
  Ha = sigmoid(Theta1*X_cv');
  pred_y = sigmoid(Theta2*[ones(1,1000);Ha]);
  
  %printf("cv data ====\n");
  [cv_mat cv_error] = computeTable(pred_y, 700);
  
  Ha = sigmoid(Theta1*X_test');
  pred_y = sigmoid(Theta2*[ones(1,1000);Ha]);
  
  %printf("test data ====\n");
  [test_mat test_error] = computeTable(pred_y, 700);
  
  
end
