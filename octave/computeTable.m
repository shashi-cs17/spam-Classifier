function [table amtr] = computeTable(pred_y, br)
  
  SZ = size(pred_y,2);
  amtr = zeros(SZ,1);
  
  train_mat = zeros(2,2);
  k=1;
  %printf("expect ham\n");
  for i=1:br,
    if pred_y(1,i) < pred_y(2,i),
      train_mat(1,2) = train_mat(1,2)+1;
      amtr(k,1) = i;
      k++;
    else
      train_mat(2,2) = train_mat(2,2)+1;
    end
  end
  
  br = br+1;
  amtr(k,1) = 0;
  k++;
  %printf("expect spam\n");
  for i=br:SZ,
    if pred_y(2,i) <= pred_y(1,i),
      train_mat(2,1) = train_mat(2,1)+1;
      amtr(k,1) = i;
      k++;
    else
      train_mat(1,1) = train_mat(1,1)+1;
    end
  end
  amtr = reshape(amtr(1:k),k,1);
  table = train_mat;
  
end
