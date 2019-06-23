function theta = trainClassifier(X,y,lambda,SZ_H,iter)
  
  epsilon = 0.25;
  
  % @param(X) --> matrix whose i'th row represents i'th training input of length
  %               20.
  % @param(y) --> ground truth labels of training examples.
  % ----------------------------------------------->>>>>>>>>>>>>>>>>
  SZ_M = size(X,2);
  SZ = SZ_H*(SZ_M+1) + 2*(SZ_H+1);
  options = optimset('GradObj','on','MaxIter',iter);
  initialTheta = rand(SZ,1)*(2*epsilon)-epsilon;
  costAndGrad = @(t) costAndGradFun(t, SZ_M, SZ_H, 2, X, y, lambda);
  
  theta = fmincg(costAndGrad, initialTheta, options);
  
end
