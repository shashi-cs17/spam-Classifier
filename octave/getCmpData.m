function [cmp] = getCmpData(tr_mat, cv_mat, te_mat)
  
  cmp = zeros(1,6);
  cmp(1) = (tr_mat(1,1)+tr_mat(2,2))/30;
  cmp(2) = (cv_mat(1,1)+cv_mat(2,2))/10;
  cmp(3) = cv_mat(1,1)/(cv_mat(1,1)+cv_mat(1,2));
  cmp(4) = cv_mat(1,1)/(cv_mat(1,1)+cv_mat(2,1));
  cmp(5) = (2*cmp(3)*cmp(4))/(cmp(3)+cmp(4));
  cmp(6) = (te_mat(1,1)+te_mat(2,2))/10;
  
end