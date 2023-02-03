@extends('products.layout')
@section('content')
  
<div class="card" style="margin:20px;">
  <div class="card-header">Create New products</div>
  <div class="card-body">
       
      <form action="{{ url('products') }}" method="post">
        {!! csrf_field() !!}
        <label>Name</label></br>
        <input type="text" name="name" id="name" class="form-control"></br>

        <label>value</label></br>
        <input type="text" name="value" id="value" class="form-control"></br>

        <label>store</label></br>
        <select name="store_id">
          @foreach($store as $item)
            <option value="{{ $item->id }}">{{ $item->name }}</option>
          @endforeach
        </select><br><br>

        <label>active</label></br>
        <input type="text" name="is_active" id="is_active" class="form-control"></br>

        <input type="submit" value="Save" class="btn btn-success"></br>
    </form>
    @if($errors->any())
      <div>
        @foreach($errors->all() as $err)
          {{ $err }}
        @endforeach
      </div>
    @endif
    
  </div>
</div>

@stop