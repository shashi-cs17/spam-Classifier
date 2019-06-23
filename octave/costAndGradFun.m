function [J grad] = costAndGradFun(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%
%
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

m = size(X, 1);
          
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

%
X = [ones(size(X,1),1) X];
ah = Theta1*X';
ah = sigmoid(ah);
ah = [ones(1,size(ah,2));ah];
a = Theta2*ah;
a = sigmoid(a);
delta3 = a;
%
O = log(1 .- a);
for i=1:m,
   O(y(i,1),i) = log(a(y(i,1),i));
   delta3(y(i,1),i) = a(y(i,1),i) - 1;
end
J = sum(sum(O));
J = -J;
J = J+(lambda/2)*(sum(sum(Theta1(:,2:end) .^ 2))+sum(sum(Theta2(:,2:end) .^ 2)));
J /= m;
%
%
delta2 = (Theta2'*delta3) .* (ah .* (1 .- ah));
%first row of delta2 corresponds to "always on" state of every training ex.
delta2 = delta2(2:end,:);
Theta2_grad = delta3*ah';
Theta2_grad(:,2:end) = Theta2_grad(:,2:end) + (lambda*Theta2(:,2:end));
Theta1_grad = delta2*X;
Theta1_grad(:,2:end) = Theta1_grad(:,2:end) + (lambda*Theta1(:,2:end));


grad = [Theta1_grad(:) ; Theta2_grad(:)];
grad /= m;

end
